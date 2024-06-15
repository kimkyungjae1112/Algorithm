#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int T;	//�׽�Ʈ ���̽� ����
	cin >> T;	//�׽�Ʈ ���̽� �Է�
	vector<vector<int>> answer(T);	//���� ������ 2���� ����
	for (int i = 0; i < T; ++i)
	{
		int N, M;	//N���� ���, M��° ����޴� ���
		cin >> N >> M;	//N, M �Է�
		int count = 0;	//M��° ������� ������ ����
		queue<int> q;	//������� ����� ť

		for (int j = 0; j < N; ++j)
		{
			q.push(j + 1);	//1������ N������ ��ȣ�� �ο��Ѵ�.
		}

		while (!q.empty())	//ť�� ������� ������ �ݺ��ϹǷ� ť�� ������� �ʴٸ� while �ݺ����� ��� ����ǵ��� �Ѵ�.
		{
			int temp = q.front();	//ť �� ���� ��Ҹ� �ӽú����� �����س��´�.
			q.pop();	//�� ���� ��Ҹ� ť���� ����.
			++count;	//�׸��� count�� 1 ������Ų��. �̷��� M��° ������� �� �� �ִ�.
			if (count != M)	//���� ��� ������ ����� M��° ����� �ƴ϶�� �ٽ� ť�� ����ִ´�.
			{
				q.push(temp);
			}
			else    //��� ������ ����� M��° ����̶�� ť�� ������� �ʰ� answer ���Ϳ� ���� �� count ������ 0���� �����.
			{
				count = 0;	//0���� �������ν� ������ ù��° ����� ó������ ������ ���۵ǰ� �Ѵ�.
				answer[i].push_back(temp);
			}
		}
	}

	for (int i = 0; i < T; ++i)	//�� ��� ����
	{
		for (int j = 0; j < answer[i].size(); ++j)
		{
			cout << answer[i][j] << " ";
		}
		printf("\n");
	}

	return 0;
}