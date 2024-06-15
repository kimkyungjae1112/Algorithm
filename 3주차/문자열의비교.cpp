#include <iostream>
#include <string>
using namespace std;

class MyString
{
private:
	char* chr;
	int length;

public:
	MyString() : chr(new char[0]), length(0) {} //기본 생성자

	MyString(char a)	//문자 하나가 들어왔을 시 생성자
	{
		chr = new char[1];
		chr[0] = a;
	}

	MyString(char* _chr)	//char형 문자열이 들어왔을 때 생성자
	{
		chr = new char[strlen(_chr)];
		length = strlen(_chr);
		for (int i = 0; i < length; ++i)
		{
			chr[i] = _chr[i];
		}
	}

	MyString(const string& str)	//string형 문자열이 들어왔을 때 생성자
	{
		chr = new char[str.length()];
		length = str.length();
		for (int i = 0; i < str.length(); ++i)
		{
			chr[i] = str[i];
		}
	}

	~MyString()	//소멸자
	{
		delete[] chr;
	}

	bool operator<(const MyString& str)
	{
		int n = min(str.length, length);	//배열 범위를 넘지 않기위해 짧은 문자열의 길이로 배열을 탐색한다.
		for (int i = 0; i < n; ++i)
		{
			if (chr[i] == str.chr[i])	//같다면 반복문 처음으로 돌아간다.
			{
				continue;
			}
			else if (chr[i] < str.chr[i])	//뒤의 문자열의 순서가 더 느림을 판별한다.
			{
				return true;	//true를 반환한다.
			}
			else if (chr[i] > str.chr[i])
			{
				return false;
			}
		}
		return false;	//만약 뒤에 있는 문자열 중 사전순이 느린 문자가 없다면 false를 반환한다.
	}

	bool operator==(const MyString& str)
	{
		int n = min(str.length, length);
		for (int i = 0; i < n; ++i)
		{
			if (chr[i] != str.chr[i])	//문자가 다른게 있다면 false를 반환한다.
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

	if (mystr1 < mystr2)	//뒤의 문자열이 앞의 문자열보다 사전순이 느리므로 true가 반환된다. 해당 if문 실행
	{
		cout << -1;
	}
	else if(mystr1 == mystr2)
	{
		cout << 0;
	}
	else    //뒤의 문자열의 사전순서가 더 빠름을 의미한다.
 	{
		cout << 1;
	}
	return 0;
}