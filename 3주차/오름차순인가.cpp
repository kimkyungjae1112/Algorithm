#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int* Height = new int[N];	//학생들의 키를 담을 배열

	for (int i = 0; i < N; ++i)
	{
		cin >> Height[i];
	}

	for (int i = 1; i < N; ++i)
	{
		if (Height[i - 1] > Height[i])	//만약 이전 학생의 키가 다음 학생의 키보다 적은 경우가 하나라도 있다면 오름차순이 아니므로
		{								//NO를 출력하고 프로그램 종료
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";	//앞선 반복문에서 한명도 걸리지 않았다면 오름차순이므로 YES 출력
	return 0;
}