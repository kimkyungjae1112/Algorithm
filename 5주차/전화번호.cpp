#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec(10000, 0);	//전화번호는 0000 ~ 9999 이므로 최대 10000개의 배열을 선언해준다.
	int N;	//테스트 케이스의 수
	cin >> N;	//테스트 케이스 입력
	
	int max_index = 0;	//0 ~ 9999까지의 전화번호를 배열의 인덱스로 활용할 것이기 때문에 나중에 전화번호를 출력할 수 있도록 인덱스 변수를 선언한다.
	int max_value = -1;	//해당 전화번호가 몇개가 있는지 식별하기 위한 변수

	for (int i = 0; i < N; ++i)
	{
		int a;	//전화번호 변수
		cin >> a;	//전화번호 입력
		vec[a]++;	//전화번호가 들어오면 해당 인덱스의 값 1 증가
		if (vec[a] > max_value || (vec[a] == max_value && a < max_index))	
		{	//들어온 전화번호의 값이 가장 많다면 해당 인덱스와 값을 저장
			//만약 들어온 전화번호의 갯수가 같다면 그 중에서 전화번호가 낮은 인덱스를 저장
			max_value = vec[a];
			max_index = a;
		}
	}

	cout << max_index;	//전화번호 출력
	
	return 0;
}