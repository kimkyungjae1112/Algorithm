#include <iostream>
#include <cmath>
using namespace std;

struct Coordinate	//õü�� ��ǥ�� ����ϴ� ����ü ����
{
	int xPos, yPos;	//���� ��ǥ x,y

	Coordinate() {}	//�⺻ ������
	Coordinate(int x, int y) : xPos(x), yPos(y) {}	//x, y ���� �޾� ��� ������ �ʱ�ȭ�ϴ� ������
};

double Distance(const Coordinate& a, const Coordinate& b)	//�ΰ��� ����ü�� �޾� �Ÿ��� �����ִ� �Լ�
{
	return sqrt(pow(a.xPos - b.xPos, 2) + pow(a.yPos - b.yPos, 2));	//�������� ���� �����ִ� sqrt, ������ ������ִ� pow
}

int main()
{
	
	int N;	
	cin >> N;	//N���� õü �Է�
	Coordinate* coordi = new Coordinate[N];	//��� ������ �𸣱� ������ �������� �������ش�.

	for (int i = 0; i < N; ++i)	//õü�� ��ǥ�� �ʱ�ȭ�ϴ� �ݺ���
	{
		int a, b;
		cin >> a >> b;
		coordi[i] = Coordinate(a, b);	//õü�� ��ǥ�� �ʱ�ȭ���ش�.
	}

	int count = 1;	//�Ÿ��� ���� õü�� �ִ��� ���� ����
	double min_distance = 30000.0; //��ǥ�� ������ 10000 ���ϱ� ������ �ִ� �Ÿ����� 28284�� ���� �� ����. ���� �ּڰ��� �����ϱ� ���� �ʱⰪ���� 30000�� �ִ´�.
	for (int i = 0; i < N; ++i)	//��� õü�� �Ÿ��� ���ϱ� ���� ���� �ݺ���
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (min_distance > Distance(coordi[i], coordi[j]))	//õü�� �ּڰ��� min_distance ������ �����Ѵ�.
			{
				min_distance = Distance(coordi[i], coordi[j]);
				count = 1;	//�Ÿ��� �ּڰ��� ���Դٴ� ���� �� ���� �ּڰ����� �Ÿ��� ���Ҵ� õü���� ���ڸ� 1�� �ʱ�ȭ �Ѵ�.
			}
			else if (min_distance == Distance(coordi[i], coordi[j]))
			{
				count++;	//�Ÿ��� �ּڰ��� ���� ���� ������ count�� ���� ���� ��Ų��.
			}
		}
	}

	printf("%.1f\n", min_distance);	//�Ҽ��� ù��° �ڸ����� ����ϴ� printf
	cout << count;	//count �� ���
	delete[] coordi;	//heap �޸� ��ȯ
	return 0;	//���α׷� ����
}