#include <iostream>
using namespace std;

bool IsPrimeNumber(int n)	//소수 판별 함수이다. true를 반환 시 소수, false를 반환 시 소수가 아닌 수이다.
{
	if (n == 1) return false;	//1은 소수가 아니고 아래 반복문에서 판단할 수 없어 미리 앞으로 빼놓는다.
	
	for (int i = 2; i * i <= n; ++i)	//우리가 입력한 숫자의 소인수가 될 수 있는 수까지 검사한다. 
	{										
		if (n % i == 0)	//그 수로 나눴을 때 나머지가 0이라면 소수가 아니다.
		{
			return false;
		}
	}
	return true; //반복문을 통과하는 수는 소수이다.
	
}

int main()
{
	int T;	//테스트 케이스 변수 선언
	cin >> T;	//몇 번 테스트할지 입력

	for (int i = 0; i < T; ++i)	//T번 숫자를 입력하고 그 수가 소수인지 판별한다.
	{
		int a;
		cin >> a;
		if (IsPrimeNumber(a))	//이 if문이 실행된다면 IsPrimeNumber() 함수가 true를 반환하므로 소수이다.
		{
			cout << "Case #" << i + 1 << endl;	//case 숫자를 맞추기 위한 +1
			cout << "YES" << endl;	//YES 출력
		}
		else //이 else문이 실행된다면 IsPrimeNumber() 함수가 false를 반환하므로 소수가 아니다.
		{
			cout << "Case #" << i + 1 << endl;	//case 숫자를 맞추기 위한 +1
			cout << "NO" << endl;	//YES 출력
		}
	}
	return 0;
}