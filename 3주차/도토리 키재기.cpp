#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N;
	
	int* Height = new int[N];
	int* Month = new int[N];

	for (int i = 1; i <= N; ++i)
	{
		cin >> Height[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		cin >> Month[i];
	}

	cin >> M;

	int max = 0;

	for (int i = 1; i <= N; ++i)	//생일이 있는 도토리 중 가장 큰 키를 찾아내는 반복문
	{
		if (Month[i] == M)	//도토리의 키는 무조건 오름차순으로 있기 때문에 마지막에 있는 도토리가 가장 크다.						
		{					//그러므로 처음부터 끝까지 도토리의 생일을 확인하며 마지막에 있는 생일이 일치하는 도토리의 인덱스를 가져온다.
			max = i;
		}
	}

	if (max != 0)	//0이 아닌 값이 들어있다면 생일이 일치하는 도토리가 있다는 것이다.
	{
		cout << Height[max];	//해당 인덱스의 값 (도토리의 키)
	}
	else
	{
		cout << -1;
	}
	return 0;
}