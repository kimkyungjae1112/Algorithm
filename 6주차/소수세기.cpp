#include <iostream>
using namespace std;

bool isPrimeNumber(int a)	//�Ҽ� �Ǻ� �Լ�
{
	if (a < 2)	//2���� ������ �Ҽ��� �ƴϹǷ� false�� ��ȯ
	{
		return false;
	}
	for (int i = 2; i * i <= a; ++i)	//�����佺�׳׽��� ü ����Ͽ� �Ҽ� �Ǻ�
	{
		if (a % i == 0)	//�������� 0�̶�� �μ��� �ִ°����� �Ҽ��� �ƴϴ�.
		{
			return false;
		}
	}
	return true;	//���� �ݺ����� ����Ѵٸ� �Ҽ��̴�.
}

int main()
{
	int T;	//�׽�Ʈ ���̽�
	cin >> T;	//�׽�Ʈ ���̽� �Է�
	int* arrays = new int[T] { 0 };	//�迭 �ʱ�ȭ

	for (int i = 0; i < T; ++i)	//�׽�Ʈ ���̽� ����ŭ �ݺ�
	{
		int a, b;	//�Է��� ����
		cin >> a >> b;
		for (int j = a; j <= b; ++j)	//�Է��� ������ �糡�� �����Ͽ� �Ҽ����� �Ǻ��Ѵ�.
		{
			if (isPrimeNumber(j))	//�Ҽ���� 1�� ���Ѵ�.
			{
				arrays[i]++;
			}
		}
	}

	for (int i = 0; i < T; ++i)	//������ش�.
	{
		printf("Case #%d:\n", i + 1);
		printf("%d\n", arrays[i]);
	}
	delete[] arrays;	//���޸� ��ȯ
	return 0;
}