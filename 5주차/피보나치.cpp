#include <iostream>
#include <vector>
using namespace std;


void Print(vector<int> & vec)	//피보나치 수열 함수를 통해 들어온 연산값을 출력해주는 함수
{
	for (int i = 0; i < vec.size(); ++i)
	{		
		cout << vec[i] << endl;
	}
}

int Fibo(int n)	//피보나치 수열을 만드는 함수
{
	int* arrays = new int[n + 1];	//연산횟수를 줄이기 위한 동적으로 배열 선언
	arrays[0] = 0;
	arrays[1] = 0;	//피보나치 수열을 한 칸 미루기 위해 arr[0], arr[1] 의 값을 0으로 초기화 하고 arr[2]부터 1로 초기화 한다.
	arrays[2] = 1;	

	for (int i = 3; i <= n; ++i)	//8자리 숫자를 정수형태로 출력하기 위한 반복문
	{
		arrays[i] = (arrays[i - 1] + arrays[i - 2]) % 100000000;
	}

	int result = arrays[n];	//연산 결과값 저장후 배열이 할당된 메모리는 반납해준다.
	delete[] arrays;
	return result;
}

int main()
{
	int T;	//테스트 케이스 개수
	cin >> T;	//테스트 케이스 입력받기
	vector<int> vec;	//연산 결과를 저장하기 위한 컨테이너
	for (int i = 0; i < T; ++i)
	{
		int a;
		cin >> a;
		vec.push_back(Fibo(a));	//컨테이너에 피보나치 함수 연산 결과 저장
	}

	Print(vec);	//결과값 출력
	return 0;
}