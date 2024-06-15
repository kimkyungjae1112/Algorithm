#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arrays = new int[N];

	int sum = 0;

	for (int i = 1; i <= N; ++i)	//1부터 N까지 순차적으로 올라간다.
	{
		for (int j = 1; j <= i; ++j)	//내부 루프로 1부터 1씩 증가되는 i만큼 더하기 수행
		{
			sum += j;
		}
	}
	cout << sum;
	delete[] arrays;
	return 0;
}