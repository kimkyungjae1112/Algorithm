#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arrays = new int[N];
	int min, index, temp;	//최솟값, 최솟값 인덱스, 임시 저장 변수

	for (int i = 0; i < N; ++i)
	{
		cin >> arrays[i];
	}

	for (int i = 0; i < N; ++i)
	{
		min = 1001;	//최솟값 설정
		for (int j = i; j < N; ++j)
		{
			if (min > arrays[j])	//최솟값과 인덱스를 결정해준다.
			{
				min = arrays[j];
				index = j;
			}
		}
		temp = arrays[i];	//해당 배열에서 최솟값과 첫번째, 두번째,,, 마지막 원소까지 정렬해준다.
		arrays[i] = min;
		arrays[index] = temp;
	}

	for (int i = 0; i < N; ++i)
	{
		cout << arrays[i] << " ";
	}
	delete[] arrays;
	return 0;
}