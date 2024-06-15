#include <iostream>
#include <cmath>
using namespace std;

int arrays[10001]; //10000 이하의 자연수
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

	float average = (float)sum / N; //평균을 더 세밀하게 보기위한 float형
	cout << average << endl;
	int min = 100001;
	int index = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (min > abs(arrays[i] - average)) // >= 말고 > 사용해서 가장 가까운 평균값이 중복되더라도 첫번째 것이 선택된다.
		{
			min = abs(arrays[i] - average);	//평균과 차이가 가장 적은 값을 min에 대입한다.
			index = i;	//해당 인덱스를 저장한다.
		}
	}

	cout << index << " " << arrays[index];
	return 0;
}