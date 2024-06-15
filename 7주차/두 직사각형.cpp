#include <iostream>
#include <cmath>
using namespace std;

int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb)	//�簢���� ��ġ�� �κ� ���� ���ϱ�
{
	int length_x = 0, length_y = 0;	//��ġ�� �κ��� x, y ����
	if (la > lb)	//ù��° �簢���� ���� x ��ǥ�� �ι�° �簢���� ���� x ��ǥ���� ũ�ٸ� ��ġ�� �κ��� ù��° �簢���� x ��ǥ���� ���۵� ���̴�.
	{
		if (ra > rb)	//�� �߿��� ù��° �簢���� x ��ǥ�� �� ũ�ٸ� �ι�° �簢���� x ��ǥ�� ��ġ�� �κ��� ���� ���̴�.
		{
			length_x = rb - la;	//���� �ι�° �簢���� ū x��ǥ���� ù��° �簢���� ���� x��ǥ�� ���ָ� ��ġ�� �κ��� x�� ���̰� ���´�.
		}
		else
		{
			length_x = ra - la;	//�ι�° �簢���� ū x ��ǥ�� ù��° �簢���� ū x ��ǥ���� ũ�ٸ� ù��° �簢���� ū x ��ǥ���� ���� x ��ǥ�� ���ָ� ��ġ�� �κ��� x �� ���̰� ���ð��̴�. 
		}
	}
	else	//ù��° �簢���� ���� x ��ǥ�� �ι�° �簢���� ���� x ��ǥ���� �۴ٸ� �ݴ�� �������ָ� �ȴ�.
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


	if (ba > bb)	//y��ǥ�� ���� ���� ���μ����� �����ϸ� �ȴ�.
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

void test_case()	//�簢���� x, y ��ǥ�� ���ϴ� �Լ�
{
	int Ax, Ay, Bx, By;	//ù��° ���簢�� ��ǥ ����
	int Px, Py, Qx, Qy;	//�ι�° ���簢�� ��ǥ ����
	cin >> Ax >> Ay >> Bx >> By;	//ù��° ���簢�� ��ǥ �Է�
	cin >> Px >> Py >> Qx >> Qy;	//�ι�° ���簢�� ��ǥ �Է�

	int la, ra, ba, ta;
	la = min(Ax, Bx);	//1��° ���簢�� �� �� ���� x ��
	ra = max(Ax, Bx);	//1��° ���簢�� �� �� ū x ��
	ta = max(Ay, By);	//1��° ���簢�� �� �� ū y ��
	ba = min(Ay, By);	//1��° ���簢�� �� �� ���� y ��

	int lb, rb, bb, tb;
	lb = min(Px, Qx);	//2��° ���簢�� �� �� ���� x ��
	rb = max(Px, Qx);	//2��° ���簢�� �� �� ū x ��
	tb = max(Py, Qy);	//2��° ���簢�� �� �� ū y ��
	bb = min(Py, Qy);	//2��° ���簢�� �� �� ���� y ��

	int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);	//��ġ�� �κ� ���� ���ϴ� �Լ�
	printf("%d\n", answer);	//��ġ�� �κ� ���� ���
}

int main()
{
	int t;	//�׽�Ʈ ���̽� ����
	cin >> t;	//�׽�Ʈ ���̽� �Է�

	for (int i = 0; i < t; ++i)	//�׽�Ʈ ���̽� ����ŭ �ݺ�
	{
		test_case();	//�˰��� ����
	}
}