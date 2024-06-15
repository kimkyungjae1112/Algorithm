#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int T;	//테스트 케이스 변수
	cin >> T;	//테스트 케이스 입력
	vector<vector<int>> answer(T);	//답을 저장할 2차원 벡터
	for (int i = 0; i < T; ++i)
	{
		int N, M;	//N명의 사람, M번째 지목받는 사람
		cin >> N >> M;	//N, M 입력
		int count = 0;	//M번째 사람인지 구별할 변수
		queue<int> q;	//사람들이 대기할 큐

		for (int j = 0; j < N; ++j)
		{
			q.push(j + 1);	//1번부터 N번까지 번호를 부여한다.
		}

		while (!q.empty())	//큐가 비어있을 때까지 반복하므로 큐가 비어있지 않다면 while 반복문이 계속 진행되도록 한다.
		{
			int temp = q.front();	//큐 맨 앞의 요소를 임시변수에 저장해놓는다.
			q.pop();	//맨 앞의 요소를 큐에서 뺀다.
			++count;	//그리고 count를 1 증가시킨다. 이렇게 M번째 사람까지 셀 수 있다.
			if (count != M)	//만약 방금 지목한 사람이 M번째 사람이 아니라면 다시 큐에 집어넣는다.
			{
				q.push(temp);
			}
			else    //방금 지목한 사람이 M번째 사람이라면 큐에 집어넣지 않고 answer 벡터에 넣은 후 count 변수를 0으로 만든다.
			{
				count = 0;	//0으로 만듦으로써 제외후 첫번째 사람이 처음으로 지목이 시작되게 한다.
				answer[i].push_back(temp);
			}
		}
	}

	for (int i = 0; i < T; ++i)	//답 출력 형식
	{
		for (int j = 0; j < answer[i].size(); ++j)
		{
			cout << answer[i][j] << " ";
		}
		printf("\n");
	}

	return 0;
}