#include <iostream>
using namespace std;

int main()
{
	int N, M;	//행운권의 수와 회원의 수
	cin >> N >> M;	//입력받기
	bool* arrays1 = new bool[N];	//행운권이 지급되었는지 true, false로 구분하기 위함

	for (int i = 0; i < N; ++i)	//행운권은 아직 발급되지 않았으므로 false로 초기화 해준다.
	{
		arrays1[i] = false;
	}

	int* arrays2 = new int[M];	//회원의 수 배열 선언 및 회원 번호 입력받기
	for (int i = 0; i < M; ++i)
	{
		cin >> arrays2[i];
	}

	int* answer = new int[M];	//발급받을 행운번호 배열
	for (int i = 0; i < M; ++i)
	{
		if (!arrays1[arrays2[i] % N])	//만약 회원 번호 % N 의 인덱스에 해당하는 행운 번호가 아직 발급되지 않은 상태라면 
		{								//해당 번호를 지급됨으로 바꾸고 배열에 저장해놓는다.
			arrays1[arrays2[i] % N] = true;
			answer[i] = arrays2[i] % N;
		}
		else    //이미 발급되어진 상태라면 1을 증가하고 N-1을 넘어간다면 0부터 탐색하도록 한다.
		{
			int a = arrays2[i] % N;
			while (arrays1[a])
			{
				a++;
				if (a > N - 1)
				{
					a = 0;
				}
				answer[i] = a;
			}
		}
	}

	for (int i = 0; i < M; ++i)	//발급받은 행운번호들을 출력한다.
	{
		cout << answer[i] << endl;
	}

	delete[] arrays1;	//힙메모리를 반납한다.
	delete[] arrays2;
	delete[] answer;
	return 0;
}