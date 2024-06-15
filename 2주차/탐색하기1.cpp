#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M; //두 자연수 N, M 입력

	int* arrays = new int[N];	//배열 선언
	for (int i = 0; i < N; ++i)
	{
		cin >> arrays[i];	//배열에 입력
	}

	for (int i = 0; i < N; ++i)
	{
		if (M == arrays[i])	//배열 요소 중 M과 같다면 
		{
			cout << i;	//해당 인덱스 출력 후 프로그램 종료
			return 0;	
		}
	}

	cout << -1;	//M을 찾지 못했다면 -1 출력
	
	delete[] arrays;
	return 0;

}