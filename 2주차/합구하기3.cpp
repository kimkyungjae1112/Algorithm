#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arrays = new int[N];

	int sum = 0;

	for (int i = 1; i <= N; ++i)	//1���� N���� ���������� �ö󰣴�.
	{
		for (int j = 1; j <= i; ++j)	//���� ������ 1���� 1�� �����Ǵ� i��ŭ ���ϱ� ����
		{
			sum += j;
		}
	}
	cout << sum;
	delete[] arrays;
	return 0;
}