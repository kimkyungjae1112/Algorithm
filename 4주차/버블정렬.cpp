#include <iostream>
using namespace std;

int main()
{
	int N;	//������ ��
	cin >> N;
	int* arrays = new int[N]; //������ ����ŭ �迭 ����
	
	for (int i = 0; i < N; ++i)
	{
		cin >> arrays[i];	//�迭�� �� ����
	}
	
	for (int i = 0; i < N; ++i)	//���������� ���� 2���� �ݺ���
	{
		for (int j = 0; j < N - 1; ++j)	//i = 0 j = 0 ~ N , i = 1 j = 0 ~ N ,,,,,
		{
			if (arrays[j] > arrays[j + 1])	//���� ���Ұ� ���� ���Һ��� ũ�ٸ� 
			{
				swap(arrays[j], arrays[j + 1]);	//������ ��ġ�� �ٲ۴�.
			}
		}
	}

	for (int i = 0; i < N; ++i)	//�迭�� �ִ� �� ���
	{
		cout << arrays[i] << " ";
	}
	delete[] arrays;	//heap �޸� ��ȯ
	return 0;
}