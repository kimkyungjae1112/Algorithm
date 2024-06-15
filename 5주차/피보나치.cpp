#include <iostream>
#include <vector>
using namespace std;


void Print(vector<int> & vec)	//�Ǻ���ġ ���� �Լ��� ���� ���� ���갪�� ������ִ� �Լ�
{
	for (int i = 0; i < vec.size(); ++i)
	{		
		cout << vec[i] << endl;
	}
}

int Fibo(int n)	//�Ǻ���ġ ������ ����� �Լ�
{
	int* arrays = new int[n + 1];	//����Ƚ���� ���̱� ���� �������� �迭 ����
	arrays[0] = 0;
	arrays[1] = 0;	//�Ǻ���ġ ������ �� ĭ �̷�� ���� arr[0], arr[1] �� ���� 0���� �ʱ�ȭ �ϰ� arr[2]���� 1�� �ʱ�ȭ �Ѵ�.
	arrays[2] = 1;	

	for (int i = 3; i <= n; ++i)	//8�ڸ� ���ڸ� �������·� ����ϱ� ���� �ݺ���
	{
		arrays[i] = (arrays[i - 1] + arrays[i - 2]) % 100000000;
	}

	int result = arrays[n];	//���� ����� ������ �迭�� �Ҵ�� �޸𸮴� �ݳ����ش�.
	delete[] arrays;
	return result;
}

int main()
{
	int T;	//�׽�Ʈ ���̽� ����
	cin >> T;	//�׽�Ʈ ���̽� �Է¹ޱ�
	vector<int> vec;	//���� ����� �����ϱ� ���� �����̳�
	for (int i = 0; i < T; ++i)
	{
		int a;
		cin >> a;
		vec.push_back(Fibo(a));	//�����̳ʿ� �Ǻ���ġ �Լ� ���� ��� ����
	}

	Print(vec);	//����� ���
	return 0;
}