#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N;	//N���� ����
	map<int, int> mp;	//key ���ڿ� ���� Ƚ���� ������ <int, int> map �����̳�
	cin >> N;	//N �Է�
	for (int i = 0; i < N; ++i)	//N�� �ݺ�
	{
		int a;
		cin >> a;
		if (mp.find(a) != mp.end())	//���� ����ڰ� �Է��� ���ڰ� �ִٸ� �ش� ������ ���� Ƚ���� 1 ������Ų��.
		{
			mp[a]++;
		}
		else //����ڰ� �Է��� ���ڰ� ó���̶�� �ش� ������ ���� Ƚ���� 1�� �ʱ�ȭ�Ѵ�.
		{
			mp[a] = 1;
		}
		//map�� �ߺ��� ������� ������ �Էµ� ������ ������ size�� ���� ����ϰ� �ش� Ű�� ���� value ���� ����ϸ� �ȴ�.
		cout << mp.size() << " " << mp[a] << endl;
	}
	return 0;
}