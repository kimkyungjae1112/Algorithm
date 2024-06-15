#include <iostream>
#include <cmath>
using namespace std;

struct Coordinate	//천체의 좌표를 기록하는 구조체 생성
{
	int xPos, yPos;	//정수 좌표 x,y

	Coordinate() {}	//기본 생성자
	Coordinate(int x, int y) : xPos(x), yPos(y) {}	//x, y 값을 받아 멤버 변수를 초기화하는 생성자
};

double Distance(const Coordinate& a, const Coordinate& b)	//두개의 구조체를 받아 거리를 구해주는 함수
{
	return sqrt(pow(a.xPos - b.xPos, 2) + pow(a.yPos - b.yPos, 2));	//제곱근의 값을 구해주는 sqrt, 제곱을 계산해주는 pow
}

int main()
{
	
	int N;	
	cin >> N;	//N개의 천체 입력
	Coordinate* coordi = new Coordinate[N];	//몇개가 들어올지 모르기 때문에 동적으로 선언해준다.

	for (int i = 0; i < N; ++i)	//천체의 좌표를 초기화하는 반복문
	{
		int a, b;
		cin >> a >> b;
		coordi[i] = Coordinate(a, b);	//천체의 좌표를 초기화해준다.
	}

	int count = 1;	//거리가 같은 천체가 있는지 세는 변수
	double min_distance = 30000.0; //좌표의 절댓값이 10000 이하기 때문에 최대 거리값은 28284를 넘을 수 없다. 따라서 최솟값을 결정하기 위한 초기값으로 30000을 넣는다.
	for (int i = 0; i < N; ++i)	//모든 천체의 거리를 구하기 위한 이중 반복문
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (min_distance > Distance(coordi[i], coordi[j]))	//천체의 최솟값을 min_distance 변수에 대입한다.
			{
				min_distance = Distance(coordi[i], coordi[j]);
				count = 1;	//거리의 최솟값이 나왔다는 것은 그 순간 최솟값으로 거리가 같았던 천체들의 숫자를 1로 초기화 한다.
			}
			else if (min_distance == Distance(coordi[i], coordi[j]))
			{
				count++;	//거리의 최솟값과 같은 값이 나오면 count의 값을 증가 시킨다.
			}
		}
	}

	printf("%.1f\n", min_distance);	//소수점 첫번째 자리까지 출력하는 printf
	cout << count;	//count 값 출력
	delete[] coordi;	//heap 메모리 반환
	return 0;	//프로그램 종료
}