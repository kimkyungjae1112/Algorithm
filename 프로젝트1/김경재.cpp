#include <stdio.h>
#include <ctime>
int main()
{
	clock_t start, finish;	//�ð��� �����ϱ� ���� clock_t ����
	double duration;	//������ �ð��� ���� ����

	int hourRadius, minRadius;
	scanf_s("%d %d", &hourRadius, &minRadius); //��ħ, ��ħ�� ���� �Է¹ޱ�

	start = clock();	//���� �ð�

	int check = (hourRadius * 12) % 360;
	//��ħ ������ 1�� ���Ҷ� ��ħ�� ������ 12�� ���Ѵ�. ���� ��ħ ������ 12�� ���� ���� ��ħ�� ���� ���̴�.
	//��ħ�� ������ 359�� �ʰ����� �����Ƿ� 360���� ���� �� ������ ���� ���Ѵ�.

	if (check == minRadius)	//��ħ�� ���� ��ħ�� �������� �츮�� �Է��� ��ħ�� ���� ���� ������ Ȯ���Ѵ�.
		printf("O\n");
	else
		printf("X\n");

	finish = clock();	//���� �� �ð�
	duration = (double)(finish - start) / CLOCKS_PER_SEC;	//�� �ɸ� �ð��� �ʴ� Ŭ�� ���� ������.
	printf("���� �ð� : %lf", duration);	//�ҿ� �ð� ���
	return 0;
}