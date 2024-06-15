#include <iostream>
using namespace std;

bool IsPrimeNumber(int n)	//�Ҽ� �Ǻ� �Լ��̴�. true�� ��ȯ �� �Ҽ�, false�� ��ȯ �� �Ҽ��� �ƴ� ���̴�.
{
	if (n == 1) return false;	//1�� �Ҽ��� �ƴϰ� �Ʒ� �ݺ������� �Ǵ��� �� ���� �̸� ������ �����´�.
	
	for (int i = 2; i * i <= n; ++i)	//�츮�� �Է��� ������ ���μ��� �� �� �ִ� ������ �˻��Ѵ�. 
	{										
		if (n % i == 0)	//�� ���� ������ �� �������� 0�̶�� �Ҽ��� �ƴϴ�.
		{
			return false;
		}
	}
	return true; //�ݺ����� ����ϴ� ���� �Ҽ��̴�.
	
}

int main()
{
	int T;	//�׽�Ʈ ���̽� ���� ����
	cin >> T;	//�� �� �׽�Ʈ���� �Է�

	for (int i = 0; i < T; ++i)	//T�� ���ڸ� �Է��ϰ� �� ���� �Ҽ����� �Ǻ��Ѵ�.
	{
		int a;
		cin >> a;
		if (IsPrimeNumber(a))	//�� if���� ����ȴٸ� IsPrimeNumber() �Լ��� true�� ��ȯ�ϹǷ� �Ҽ��̴�.
		{
			cout << "Case #" << i + 1 << endl;	//case ���ڸ� ���߱� ���� +1
			cout << "YES" << endl;	//YES ���
		}
		else //�� else���� ����ȴٸ� IsPrimeNumber() �Լ��� false�� ��ȯ�ϹǷ� �Ҽ��� �ƴϴ�.
		{
			cout << "Case #" << i + 1 << endl;	//case ���ڸ� ���߱� ���� +1
			cout << "NO" << endl;	//YES ���
		}
	}
	return 0;
}