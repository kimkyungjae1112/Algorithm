#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long h[100001];	//������׷��� ���̸� ���� �迭

int main()
{
	int T;	//�׽�Ʈ ���̽�
	cin >> T;	//�׽�Ʈ���̽� �Է�
	vector<int> answer;	//�� �׽�Ʈ ���̽��� �ִ� ���̸� ���� ����
	for (int i = 0; i < T; ++i)
	{
		stack<int> st;	//������׷��� �ε����� �����س��� stack
		int n;	//������׷��� ����
		long long max = -1;	//������ �ִ�
		cin >> n;	//������׷� ���� �Է�

		for (int j = 0; j < n; ++j)	//������׷� ���� �Է�
			cin >> h[j];

		//Ư�� ���뺸�� ������ ������ ���밡 �� ũ�ų� ������ ���� ����� ���� �� �ִ� �ִ� ���簢���� �ʺ� �� Ŀ���Եȴ�.
		//�ݴ�� ������ ���°� ���� ������ Ư�� ���밡 ���簢���� �������� �ȴ�.
		for (int j = 0; j < n; ++j)
		{
			while (!st.empty() && h[j] < h[st.top()])	//������ �����������, ���簢���� �ʺ�� �ε����� �����ϴ�.
			{
				long long hTop = h[st.top()];
				int l = j;
				st.pop();

				if (!st.empty()) //������ ��������� ������, ���簢���� �ʺ� ���
					l = j - st.top() - 1;

				if (max < l * hTop) //���簢���� �ִ� ����
					max = l * hTop;
			}

			//���ÿ� �ε��� ����
			st.push(j);
		}

		while (!st.empty())	//��� ������� ��ȸ�� ���ĵ� ���ÿ� ó������ ���� ������� �ε������� �����ִٸ� Ư�� ���뺸�� ���� ������� ���� ��Ȳ�� ���̴�.
		{
			long long hTop = h[st.top()];
			int l = n;
			st.pop();

			if (!st.empty())
				l = n - st.top() - 1;
			if (max < l * hTop)
				max = l * hTop;
		}

		answer.push_back(max);	//�ִ� �Է�
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << '\n';	//��� ����
	}
	return 0;
}
