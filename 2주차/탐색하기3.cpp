#include <iostream>
#include <cmath>
using namespace std;

int arrays[10001]; //10000 ������ �ڿ���
int main()
{
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arrays[i];
		sum += arrays[i];
	}

	float average = (float)sum / N; //����� �� �����ϰ� �������� float��
	cout << average << endl;
	int min = 100001;
	int index = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (min > abs(arrays[i] - average)) // >= ���� > ����ؼ� ���� ����� ��հ��� �ߺ��Ǵ��� ù��° ���� ���õȴ�.
		{
			min = abs(arrays[i] - average);	//��հ� ���̰� ���� ���� ���� min�� �����Ѵ�.
			index = i;	//�ش� �ε����� �����Ѵ�.
		}
	}

	cout << index << " " << arrays[index];
	return 0;
}