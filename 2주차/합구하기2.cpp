#include <iostream>
using namespace std;

int main()
{
	int N, P, Q;
	cin >> N >> P >> Q;

	int weight;	//���� ������ �ۼ�
	int weightSum = 0;	//������ ����
	int count = 0;	//���̱ⱸ ������ ���� P�� ���� �ʴ� ��� ī��Ʈ

	for (int i = 0; i < N; ++i)
	{
		cin >> weight;	//������ �Է�

		if (weight < P)	//P�� ���� �ʴ´ٸ� ī��Ʈ, ������ ���ϱ�
		{
			weightSum += weight;
			count++;
		}
	}

	cout << count << " " << weightSum << '\n';
	if (weightSum < Q) //������ ������ Q�� ���� �ʴ´ٸ� YES ��� �ƴϸ� NO ���
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}