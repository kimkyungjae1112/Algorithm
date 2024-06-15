#include <iostream>
#include <ctime>
using namespace std;

long long gcd(int a, int b)	//�ִ� ����� ���ϴ� �Լ�
{	//���ڿ� ���� ������ ������ �������.
	if (b == 0) return a; //a % b == 0�� �Ǵ� ������ �ִ������� ������ �����̴�.
	gcd(b, a % b); //���
}

int main()	//��� ������ ���簢�� ���� ��ü ���簢������ ���ο� ������ �ִ������� �������� �� ���̴�.
{
	int W, H;	//���� ���� ����
	cin >> W >> H;	//���� ���� �Է�
	clock_t start, end;	//�ð� ����
	double duration;	//�ð��� ����

	start = clock();
	long long GCD = gcd(W, H);	//���� ������ �ִ� �����

	long long totalSquares = W * H;	//��ü ���簢�� ��
	long long lostSquares = GCD * GCD;	//�ִ����� ����
	long long availableSquares = totalSquares - lostSquares;	//��ü���� ���ش�.
	end = clock();

	cout << availableSquares << endl; //��� ����
	duration = (double)(end - start) / CLOCKS_PER_SEC; //�ɸ� �ð� ���
	cout << "����ð�: " << duration << "��";	//�ð� ���
}