#include <iostream>
using namespace std;

int arrays[200001];	//20만 이하의 자연수를 담을 배열

int main()
{
	int N;	//N개의 정수 변수
	cin >> N;	//N개의 정수 입력

	for (int i = 0; i < N; ++i)	//N번만큼 반복
	{
		int a;	//주어지는 숫자
		cin >> a;	//숫자 입력
		arrays[a]++;	//그 숫자를 인덱스로 사용해 배열을 1 증가
		if (arrays[a] > 1)	//만약 그 인덱스에 해당하는 배열 요소가 1이 넘어간다면 이미 등장했던 숫자
		{
			cout << "DUPLICATED" << endl;
		}
		else //아니라면 처음 나오는 숫자
		{
			cout << "OK" << endl;
		}
	}

	return 0;
}