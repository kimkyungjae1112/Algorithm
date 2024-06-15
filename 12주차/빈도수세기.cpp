#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N;	//N개의 정수
	map<int, int> mp;	//key 숫자와 나온 횟수를 저장할 <int, int> map 컨테이너
	cin >> N;	//N 입력
	for (int i = 0; i < N; ++i)	//N번 반복
	{
		int a;
		cin >> a;
		if (mp.find(a) != mp.end())	//만약 사용자가 입력한 숫자가 있다면 해당 숫자의 출현 횟수를 1 증가시킨다.
		{
			mp[a]++;
		}
		else //사용자가 입력한 숫자가 처음이라면 해당 숫자의 출현 횟수를 1로 초기화한다.
		{
			mp[a] = 1;
		}
		//map은 중복을 허용하지 않으니 입력된 숫자의 종류는 size를 통해 출력하고 해당 키에 대한 value 값을 출력하면 된다.
		cout << mp.size() << " " << mp[a] << endl;
	}
	return 0;
}