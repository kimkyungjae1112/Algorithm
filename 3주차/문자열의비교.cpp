#include <iostream>
#include <string>
using namespace std;

class MyString
{
private:
	char* chr;
	int length;

public:
	MyString() : chr(new char[0]), length(0) {} //�⺻ ������

	MyString(char a)	//���� �ϳ��� ������ �� ������
	{
		chr = new char[1];
		chr[0] = a;
	}

	MyString(char* _chr)	//char�� ���ڿ��� ������ �� ������
	{
		chr = new char[strlen(_chr)];
		length = strlen(_chr);
		for (int i = 0; i < length; ++i)
		{
			chr[i] = _chr[i];
		}
	}

	MyString(const string& str)	//string�� ���ڿ��� ������ �� ������
	{
		chr = new char[str.length()];
		length = str.length();
		for (int i = 0; i < str.length(); ++i)
		{
			chr[i] = str[i];
		}
	}

	~MyString()	//�Ҹ���
	{
		delete[] chr;
	}

	bool operator<(const MyString& str)
	{
		int n = min(str.length, length);	//�迭 ������ ���� �ʱ����� ª�� ���ڿ��� ���̷� �迭�� Ž���Ѵ�.
		for (int i = 0; i < n; ++i)
		{
			if (chr[i] == str.chr[i])	//���ٸ� �ݺ��� ó������ ���ư���.
			{
				continue;
			}
			else if (chr[i] < str.chr[i])	//���� ���ڿ��� ������ �� ������ �Ǻ��Ѵ�.
			{
				return true;	//true�� ��ȯ�Ѵ�.
			}
			else if (chr[i] > str.chr[i])
			{
				return false;
			}
		}
		return false;	//���� �ڿ� �ִ� ���ڿ� �� �������� ���� ���ڰ� ���ٸ� false�� ��ȯ�Ѵ�.
	}

	bool operator==(const MyString& str)
	{
		int n = min(str.length, length);
		for (int i = 0; i < n; ++i)
		{
			if (chr[i] != str.chr[i])	//���ڰ� �ٸ��� �ִٸ� false�� ��ȯ�Ѵ�.
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	string str1;
	string str2;
	cin >> str1 >> str2;
	MyString mystr1(str1);
	MyString mystr2(str2);

	if (mystr1 < mystr2)	//���� ���ڿ��� ���� ���ڿ����� �������� �����Ƿ� true�� ��ȯ�ȴ�. �ش� if�� ����
	{
		cout << -1;
	}
	else if(mystr1 == mystr2)
	{
		cout << 0;
	}
	else    //���� ���ڿ��� ���������� �� ������ �ǹ��Ѵ�.
 	{
		cout << 1;
	}
	return 0;
}