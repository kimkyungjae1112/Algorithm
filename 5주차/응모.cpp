#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N;	//������ �� 
	cin >> N;	//������ �� �Է�
	set<int> st;	//�ڵ����� �ߺ� ���� �� ������������ �������ִ� set ���

	for (int i = 0; i < N; ++i)	//set�� ������ �Է�
	{
		int a;
		cin >> a;
		st.insert(a);
	}

	set<int>::iterator iter = st.begin();	//set�� ��ȸ�ϱ� ���� �ݺ���
	while (iter != st.end())	//�����̳��� ��ü�� ��ȸ�ϴ� �ݺ���
	{
		cout << *iter << " ";	//�����̳� ���� ��Ҹ� ��� �� ����
		iter++;	//�ϳ��� �Űܰ���.
	}
	return 0;
}