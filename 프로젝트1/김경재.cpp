#include <stdio.h>
#include <ctime>
int main()
{
	clock_t start, finish;	//시간을 측정하기 위한 clock_t 변수
	double duration;	//측정된 시간을 담을 변수

	int hourRadius, minRadius;
	scanf_s("%d %d", &hourRadius, &minRadius); //시침, 분침의 각도 입력받기

	start = clock();	//현재 시간

	int check = (hourRadius * 12) % 360;
	//시침 각도가 1도 변할때 분침의 각도는 12도 변한다. 따라서 시침 각도에 12를 곱한 값을 분침과 비교할 것이다.
	//분침의 각도는 359를 초과하지 않으므로 360으로 나눈 후 나머지 값을 취한다.

	if (check == minRadius)	//시침에 따른 분침의 각도값과 우리가 입력한 분침의 각도 값이 같은지 확인한다.
		printf("O\n");
	else
		printf("X\n");

	finish = clock();	//실행 후 시간
	duration = (double)(finish - start) / CLOCKS_PER_SEC;	//총 걸린 시간을 초당 클럭 수로 나눈다.
	printf("실행 시간 : %lf", duration);	//소요 시간 출력
	return 0;
}