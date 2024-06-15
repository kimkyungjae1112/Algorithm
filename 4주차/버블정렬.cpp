#include <iostream>
using namespace std;

int main()
{
	int N;	//데이터 수
	cin >> N;
	int* arrays = new int[N]; //데이터 수만큼 배열 선언
	
	for (int i = 0; i < N; ++i)
	{
		cin >> arrays[i];	//배열에 값 삽입
	}
	
	for (int i = 0; i < N; ++i)	//버블정렬을 위한 2개의 반복문
	{
		for (int j = 0; j < N - 1; ++j)	//i = 0 j = 0 ~ N , i = 1 j = 0 ~ N ,,,,,
		{
			if (arrays[j] > arrays[j + 1])	//앞의 원소가 뒤의 원소보다 크다면 
			{
				swap(arrays[j], arrays[j + 1]);	//서로의 위치를 바꾼다.
			}
		}
	}

	for (int i = 0; i < N; ++i)	//배열에 있는 값 출력
	{
		cout << arrays[i] << " ";
	}
	delete[] arrays;	//heap 메모리 반환
	return 0;
}