#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M; //�� �ڿ��� N, M �Է�

	int* arrays = new int[N];	//�迭 ����
	for (int i = 0; i < N; ++i)
	{
		cin >> arrays[i];	//�迭�� �Է�
	}

	for (int i = 0; i < N; ++i)
	{
		if (M == arrays[i])	//�迭 ��� �� M�� ���ٸ� 
		{
			cout << i;	//�ش� �ε��� ��� �� ���α׷� ����
			return 0;	
		}
	}

	cout << -1;	//M�� ã�� ���ߴٸ� -1 ���
	
	delete[] arrays;
	return 0;

}