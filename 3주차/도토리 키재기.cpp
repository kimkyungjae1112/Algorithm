#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N;
	
	int* Height = new int[N];
	int* Month = new int[N];

	for (int i = 1; i <= N; ++i)
	{
		cin >> Height[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		cin >> Month[i];
	}

	cin >> M;

	int max = 0;

	for (int i = 1; i <= N; ++i)	//������ �ִ� ���丮 �� ���� ū Ű�� ã�Ƴ��� �ݺ���
	{
		if (Month[i] == M)	//���丮�� Ű�� ������ ������������ �ֱ� ������ �������� �ִ� ���丮�� ���� ũ��.						
		{					//�׷��Ƿ� ó������ ������ ���丮�� ������ Ȯ���ϸ� �������� �ִ� ������ ��ġ�ϴ� ���丮�� �ε����� �����´�.
			max = i;
		}
	}

	if (max != 0)	//0�� �ƴ� ���� ����ִٸ� ������ ��ġ�ϴ� ���丮�� �ִٴ� ���̴�.
	{
		cout << Height[max];	//�ش� �ε����� �� (���丮�� Ű)
	}
	else
	{
		cout << -1;
	}
	return 0;
}