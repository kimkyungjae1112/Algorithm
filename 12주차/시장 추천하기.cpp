#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N;	//�׽�Ʈ ���̽� 
	int max = 0;	//�ִ� ��ǥ �� �ʱⰪ

	map<string, int> mp;	//�� �ĺ� �̸��� ��ǥ ���� �����ϴ� map
	cin >> N;	//�׽�Ʈ ���̽� �Է�
	for (int i = 0; i < N; ++i)
	{
		string name;	//�ĺ� �̸�
		cin >> name;	//�ĺ� �̸� �Է�

		if (mp.find(name) != mp.end()) //�ĺ� �̸��� �̹� ���� ���¸� ����
		{
			mp[name]++;
			if (max < mp[name])	//�ĺ� �� ���� ���� ǥ�� ���� ã�´�.
			{
				max = mp[name];
			}
		}
		else //�ĺ� �̸��� ������ �ʾҴٸ� 1�� �ʱ�ȭ
		{	
			mp[name] = 1;
		}
	}

	cout << max << endl;	//���� ���� ǥ ���
	for (const auto& element : mp)
	{
		if (element.second == max)	//���� ���� ǥ�� ���� �ĺ����� �̸� ���
		{
			cout << element.first << " ";	//map �����̳ʴ� �ڵ����� �������� ������ �����Ѵ�.
		}
	}
}