#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int* Height = new int[N];	//�л����� Ű�� ���� �迭

	for (int i = 0; i < N; ++i)
	{
		cin >> Height[i];
	}

	for (int i = 1; i < N; ++i)
	{
		if (Height[i - 1] > Height[i])	//���� ���� �л��� Ű�� ���� �л��� Ű���� ���� ��찡 �ϳ��� �ִٸ� ���������� �ƴϹǷ�
		{								//NO�� ����ϰ� ���α׷� ����
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";	//�ռ� �ݺ������� �Ѹ� �ɸ��� �ʾҴٸ� ���������̹Ƿ� YES ���
	return 0;
}