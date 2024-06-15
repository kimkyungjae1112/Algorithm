#include <iostream>
using namespace std;

int main()
{
	int N, M;	//������ ���� ȸ���� ��
	cin >> N >> M;	//�Է¹ޱ�
	bool* arrays1 = new bool[N];	//������ ���޵Ǿ����� true, false�� �����ϱ� ����

	for (int i = 0; i < N; ++i)	//������ ���� �߱޵��� �ʾ����Ƿ� false�� �ʱ�ȭ ���ش�.
	{
		arrays1[i] = false;
	}

	int* arrays2 = new int[M];	//ȸ���� �� �迭 ���� �� ȸ�� ��ȣ �Է¹ޱ�
	for (int i = 0; i < M; ++i)
	{
		cin >> arrays2[i];
	}

	int* answer = new int[M];	//�߱޹��� ����ȣ �迭
	for (int i = 0; i < M; ++i)
	{
		if (!arrays1[arrays2[i] % N])	//���� ȸ�� ��ȣ % N �� �ε����� �ش��ϴ� ��� ��ȣ�� ���� �߱޵��� ���� ���¶�� 
		{								//�ش� ��ȣ�� ���޵����� �ٲٰ� �迭�� �����س��´�.
			arrays1[arrays2[i] % N] = true;
			answer[i] = arrays2[i] % N;
		}
		else    //�̹� �߱޵Ǿ��� ���¶�� 1�� �����ϰ� N-1�� �Ѿ�ٸ� 0���� Ž���ϵ��� �Ѵ�.
		{
			int a = arrays2[i] % N;
			while (arrays1[a])
			{
				a++;
				if (a > N - 1)
				{
					a = 0;
				}
				answer[i] = a;
			}
		}
	}

	for (int i = 0; i < M; ++i)	//�߱޹��� ����ȣ���� ����Ѵ�.
	{
		cout << answer[i] << endl;
	}

	delete[] arrays1;	//���޸𸮸� �ݳ��Ѵ�.
	delete[] arrays2;
	delete[] answer;
	return 0;
}