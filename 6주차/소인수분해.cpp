#include <iostream>
using namespace std;

int main()
{
	int T;	//테스트케이스 변수
	cin >> T;	//테스트케이스 입력받기
	int* arrays = new int[T];	//소인수분해할 숫자 입력받기
	for (int i = 0; i < T; ++i)
	{
		cin >> arrays[i];
	}

	for (int i = 0; i < T; ++i)
	{
		int a = 2;	//소인수분해는 1보다 큰 자연수를 소인수듣만의 곱으로 나타내기에 나누는 수를 2로 초기화한다.
		printf("#%d\n", i + 1);	//출력 형식
		while (arrays[i] % a != arrays[i])	//a로 나눈 나머지가 원래의 값과 같다면 소인수 분해를 하지 못하는 상태에 이르렀다고 판단한다.
		{
			if (arrays[i] % a == 0)	//a로 나눈 나머지가 0이라면
			{
				cout << a << " ";	//해당 값을 출력한다.
				arrays[i] /= a;	//나눈 몫을 다시 저장하고 소인수분해를 이어간다.
				continue;	//여기서 a는 증가할 필요 없다.
			}
			a++;	//위 조건문을 빠져나왔다면 해당 값으로 소인수분해를 하지 못했기에 1씩 증가시키며 인수를 찾는다.
		}
		cout << '\n';	//출력 형식
	}
	delete[] arrays;	//힙메모리 반환
	return 0;
}