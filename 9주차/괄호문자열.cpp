#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<char> st;	//괄호를 저장할 스택
	int T;	//테스트 케이스
	cin >> T;	//테스트 케이스 입력
	bool* arrays = new bool[T] { 0, };	//올바른 괄호 문자열인지 아닌지를 저장할 bool형 배열

	for (int i = 0; i < T; ++i)	//테스트 케이스 수만큼 진행
	{
		string a;	//괄호를 입력할 string 변수
		cin >> a;	//괄호 입력

		for (int j = 0; j < a.size(); ++j)	//string은 인덱스로 접근가능하다.
		{
			if (st.empty() && a[j] == ')')	//스택이 비어있는데 닫는 괄호부터 오면 안된다. 
			{
				arrays[i] = false;	//bool 배열에 거짓값을 저장한다.
				break;	//잘못된걸 안 이상 더이상 문자열에 대해 탐색하지 않아도 된다.
			}
			else if (a[j] == '(')	//여는 괄호면 언제든지 스택에 삽입한다.
			{
				st.push(a[j]);
			}
			else if (a[j] == ')')	//닫는 괄호라면 삽입하지 않고 스택에 있던 열린 괄호를 꺼낸다.
			{
				st.pop();	//열린 괄호를 꺼내면서 짝이 맞는지 숫자를 센다.

				if (st.empty() && j + 1 == a.size())	//만약 마지막 닫힌 괄호로 인해 pop을 진행했을 때 스택이 비어있다면 모든 괄호가 올바르게 되어있다는 것을 알 수 있다.
				{
					arrays[i] = true;	//bool 배열에 참값을 저장한다.
				}
			}
		}
		if (!st.empty())	//만약 닫힌 괄호 수가 부족해 스택에 열린 괄호가 남아있다면 잘못된 괄호 문자열이기에 bool 배열에 거짓값을 저장한다.
		{
			arrays[i] = false;
		}

		while (!st.empty())	//스택에 괄호가 남아있다면 나머지 값들을 빼준다.
		{
			st.pop();
		}
	}

	for (int i = 0; i < T; ++i)	//배열에 저장된 값에 따라 출력을 달리해준다.
	{
		if (arrays[i])	//i번째 괄호문자열이 참이었다면 YES,
		{
			cout << "YES" << endl;
		}
		else	//거짓이었다면 NO를 출력해준다.
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}