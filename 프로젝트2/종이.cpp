#include <iostream>
#include <ctime>
using namespace std;

long long gcd(int a, int b)	//최대 공약수 구하는 함수
{	//인자에 들어가는 숫자의 순서는 상관없다.
	if (b == 0) return a; //a % b == 0이 되는 순간이 최대공약수가 나오는 순간이다.
	gcd(b, a % b); //재귀
}

int main()	//사용 가능한 정사각형 수는 전체 정사각형에서 가로와 세로의 최대공약수의 제곱값을 뺀 값이다.
{
	int W, H;	//가로 세로 변수
	cin >> W >> H;	//가로 세로 입력
	clock_t start, end;	//시간 변수
	double duration;	//시간초 변수

	start = clock();
	long long GCD = gcd(W, H);	//가로 세로의 최대 공약수

	long long totalSquares = W * H;	//전체 정사각형 수
	long long lostSquares = GCD * GCD;	//최대공약수 제곱
	long long availableSquares = totalSquares - lostSquares;	//전체에서 빼준다.
	end = clock();

	cout << availableSquares << endl; //출력 형식
	duration = (double)(end - start) / CLOCKS_PER_SEC; //걸린 시간 계산
	cout << "실행시간: " << duration << "초";	//시간 출력
}