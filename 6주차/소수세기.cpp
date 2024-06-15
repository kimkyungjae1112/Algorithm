#include <iostream>
using namespace std;

bool isPrimeNumber(int a)	//소수 판별 함수
{
	if (a < 2)	//2보다 작으면 소수가 아니므로 false를 반환
	{
		return false;
	}
	for (int i = 2; i * i <= a; ++i)	//에라토스테네스의 체 사용하여 소수 판별
	{
		if (a % i == 0)	//나머지가 0이라면 인수가 있는것으로 소수가 아니다.
		{
			return false;
		}
	}
	return true;	//위의 반복문을 통과한다면 소수이다.
}

int main()
{
	int T;	//테스트 케이스
	cin >> T;	//테스트 케이스 입력
	int* arrays = new int[T] { 0 };	//배열 초기화

	for (int i = 0; i < T; ++i)	//테스트 케이스 수만큼 반복
	{
		int a, b;	//입력할 숫자
		cin >> a >> b;
		for (int j = a; j <= b; ++j)	//입력한 숫자의 양끝을 포함하여 소수인지 판별한다.
		{
			if (isPrimeNumber(j))	//소수라면 1씩 더한다.
			{
				arrays[i]++;
			}
		}
	}

	for (int i = 0; i < T; ++i)	//출력해준다.
	{
		printf("Case #%d:\n", i + 1);
		printf("%d\n", arrays[i]);
	}
	delete[] arrays;	//힙메모리 반환
	return 0;
}