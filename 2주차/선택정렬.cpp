#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arrays = new int[N];
	int min, index, temp;	//�ּڰ�, �ּڰ� �ε���, �ӽ� ���� ����

	for (int i = 0; i < N; ++i)
	{
		cin >> arrays[i];
	}

	for (int i = 0; i < N; ++i)
	{
		min = 1001;	//�ּڰ� ����
		for (int j = i; j < N; ++j)
		{
			if (min > arrays[j])	//�ּڰ��� �ε����� �������ش�.
			{
				min = arrays[j];
				index = j;
			}
		}
		temp = arrays[i];	//�ش� �迭���� �ּڰ��� ù��°, �ι�°,,, ������ ���ұ��� �������ش�.
		arrays[i] = min;
		arrays[index] = temp;
	}

	for (int i = 0; i < N; ++i)
	{
		cout << arrays[i] << " ";
	}
	delete[] arrays;
	return 0;
}