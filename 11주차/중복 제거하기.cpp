#include <iostream>
using namespace std;

int arrays[200001];	//20�� ������ �ڿ����� ���� �迭

int main()
{
	int N;	//N���� ���� ����
	cin >> N;	//N���� ���� �Է�

	for (int i = 0; i < N; ++i)	//N����ŭ �ݺ�
	{
		int a;	//�־����� ����
		cin >> a;	//���� �Է�
		arrays[a]++;	//�� ���ڸ� �ε����� ����� �迭�� 1 ����
		if (arrays[a] > 1)	//���� �� �ε����� �ش��ϴ� �迭 ��Ұ� 1�� �Ѿ�ٸ� �̹� �����ߴ� ����
		{
			cout << "DUPLICATED" << endl;
		}
		else //�ƴ϶�� ó�� ������ ����
		{
			cout << "OK" << endl;
		}
	}

	return 0;
}