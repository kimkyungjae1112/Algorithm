#include <iostream>
#include <cmath>
using namespace std;

int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb)	//사각형의 겹치는 부분 넓이 구하기
{
	int length_x = 0, length_y = 0;	//겹치는 부분의 x, y 길이
	if (la > lb)	//첫번째 사각형의 작은 x 좌표가 두번째 사각형의 작은 x 좌표보다 크다면 겹치는 부분은 첫번째 사각형의 x 좌표부터 시작될 것이다.
	{
		if (ra > rb)	//그 중에서 첫번째 사각형의 x 좌표가 더 크다면 두번째 사각형의 x 좌표가 겹치는 부분의 끝일 것이다.
		{
			length_x = rb - la;	//따라서 두번째 사각형의 큰 x좌표에서 첫번째 사각형의 작은 x좌표를 빼주면 겹치는 부분의 x축 길이가 나온다.
		}
		else
		{
			length_x = ra - la;	//두번째 사각형의 큰 x 좌표가 첫번째 사각형의 큰 x 좌표보다 크다면 첫번째 사각형의 큰 x 좌표에서 작은 x 좌표를 빼주면 겹치는 부분의 x 축 길이가 나올것이다. 
		}
	}
	else	//첫번째 사각형의 작은 x 좌표가 두번째 사각형의 작은 x 좌표보다 작다면 반대로 진행해주면 된다.
	{
		if (ra > rb)
		{
			length_x = rb - lb;
		}
		else
		{
			length_x = ra - lb;
		}
	}


	if (ba > bb)	//y좌표도 위와 같은 프로세스로 진행하면 된다.
	{
		if (ta > tb)
		{
			length_y = tb - ba;
		}
		else
		{
			length_y = ta - ba;
		}
	}
	else
	{
		if (ta > tb)
		{
			length_y = tb - bb;
		}
		else
		{
			length_y = ta - bb;
		}
	}

	return length_x * length_y;
}

void test_case()	//사각형의 x, y 좌표를 구하는 함수
{
	int Ax, Ay, Bx, By;	//첫번째 직사각형 좌표 변수
	int Px, Py, Qx, Qy;	//두번째 직사각형 좌표 변수
	cin >> Ax >> Ay >> Bx >> By;	//첫번째 직사각형 좌표 입력
	cin >> Px >> Py >> Qx >> Qy;	//두번째 직사각형 좌표 입력

	int la, ra, ba, ta;
	la = min(Ax, Bx);	//1번째 직사각형 중 젤 작은 x 값
	ra = max(Ax, Bx);	//1번째 직사각형 중 젤 큰 x 값
	ta = max(Ay, By);	//1번째 직사각형 중 젤 큰 y 값
	ba = min(Ay, By);	//1번째 직사각형 중 젤 작은 y 값

	int lb, rb, bb, tb;
	lb = min(Px, Qx);	//2번째 직사각형 중 젤 작은 x 값
	rb = max(Px, Qx);	//2번째 직사각형 중 젤 큰 x 값
	tb = max(Py, Qy);	//2번째 직사각형 중 젤 큰 y 값
	bb = min(Py, Qy);	//2번째 직사각형 중 젤 작은 y 값

	int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);	//겹치는 부분 넓이 구하는 함수
	printf("%d\n", answer);	//겹치는 부분 넓이 출력
}

int main()
{
	int t;	//테스트 케이스 변수
	cin >> t;	//테스트 케이스 입력

	for (int i = 0; i < t; ++i)	//테스트 케이스 수만큼 반복
	{
		test_case();	//알고리즘 수행
	}
}