#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int T;	//테스트 케이스의 수
	cin >> T;	//테스트 케이스 입력

	int* arrays = new int[T];	//원의 반지름을 담을 배열 선언

	for (int i = 0; i < T; ++i)
	{
		cin >> arrays[i];	//테스트 케이스의 수만큼 원의 반지름 입력
	}


	for (int k = 0; k < T; ++k)	//테스트 케이스의 수만큼 픽셀의 수 구하기
	{
		int count = 0;	//픽셀의 수를 담을 변수 선언
		for (int i = 0; i <= arrays[k]; ++i)	//1사분면의 픽셀 수를 구한뒤 *4를 해주면 전체 픽셀 값을 구할 수 있다.
		{
			for (int j = 0; j <= arrays[k]; ++j)	//i는 x 좌표, j는 y 좌표 
			{
				if (sqrt((i * i) + (j * j)) < arrays[k])	//원 내부에 있는 점들의 갯수만큼 픽셀의 수가 된다. 하지만 원과 같은 선상에 있는 점이라면 포함시키지 않는다.
				{
					count++; //점의 갯수만큼 증가시킨다.
				}
			}
		}
		
		cout << "#" << k + 1 << '\n' << count * 4 << endl;	//1사분면에서 구한 픽셀의 갯수에 *4를 해주면 원이 감싸고 있는 픽셀값을 구할 수 있다.
	}

	delete[] arrays;	//메모리를 반납해준다.
	return 0;
}