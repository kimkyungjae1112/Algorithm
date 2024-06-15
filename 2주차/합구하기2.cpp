#include <iostream>
using namespace std;

int main()
{
	int N, P, Q;
	cin >> N >> P >> Q;

	int weight;	//개인 몸무게 작성
	int weightSum = 0;	//몸무게 총합
	int count = 0;	//놀이기구 몸무게 제한 P를 넘지 않는 사람 카운트

	for (int i = 0; i < N; ++i)
	{
		cin >> weight;	//몸무게 입력

		if (weight < P)	//P를 넘지 않는다면 카운트, 몸무게 더하기
		{
			weightSum += weight;
			count++;
		}
	}

	cout << count << " " << weightSum << '\n';
	if (weightSum < Q) //몸무게 총합이 Q를 넘지 않는다면 YES 출력 아니면 NO 출력
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}