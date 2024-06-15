#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long h[100001];	//히스토그램의 높이를 담을 배열

int main()
{
	int T;	//테스트 케이스
	cin >> T;	//테스트케이스 입력
	vector<int> answer;	//각 테스트 케이스의 최대 넓이를 담을 벡터
	for (int i = 0; i < T; ++i)
	{
		stack<int> st;	//히스토그램의 인덱스를 저장해놓을 stack
		int n;	//히스토그램의 갯수
		long long max = -1;	//넓이의 최댓값
		cin >> n;	//히스토그램 갯수 입력

		for (int j = 0; j < n; ++j)	//히스토그램 높이 입력
			cin >> h[j];

		//특정 막대보다 다음에 나오는 막대가 더 크거나 같으면 이전 막대로 만들 수 있는 최대 직사각형의 너비가 더 커지게된다.
		//반대로 다음에 오는게 작은 막대라면 특정 막대가 직사각형의 마지막이 된다.
		for (int j = 0; j < n; ++j)
		{
			while (!st.empty() && h[j] < h[st.top()])	//스택이 비워져있으면, 직사각형의 너비는 인덱스와 동일하다.
			{
				long long hTop = h[st.top()];
				int l = j;
				st.pop();

				if (!st.empty()) //스택이 비워져있지 않으면, 직사각형의 너비 계산
					l = j - st.top() - 1;

				if (max < l * hTop) //직사각형의 최댓값 갱신
					max = l * hTop;
			}

			//스택에 인덱스 삽입
			st.push(j);
		}

		while (!st.empty())	//모든 막대들의 순회를 마쳐도 스택에 처리되지 않은 막대들의 인덱스들이 남아있다면 특정 막대보다 작은 막대들이 들어온 상황일 것이다.
		{
			long long hTop = h[st.top()];
			int l = n;
			st.pop();

			if (!st.empty())
				l = n - st.top() - 1;
			if (max < l * hTop)
				max = l * hTop;
		}

		answer.push_back(max);	//최댓값 입력
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << '\n';	//출력 형식
	}
	return 0;
}
