#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N;	//테스트 케이스 
	int max = 0;	//최다 득표 수 초기값

	map<string, int> mp;	//각 후보 이름과 득표 수를 저장하는 map
	cin >> N;	//테스트 케이스 입력
	for (int i = 0; i < N; ++i)
	{
		string name;	//후보 이름
		cin >> name;	//후보 이름 입력

		if (mp.find(name) != mp.end()) //후보 이름이 이미 나온 상태면 증가
		{
			mp[name]++;
			if (max < mp[name])	//후보 중 가장 많은 표의 수를 찾는다.
			{
				max = mp[name];
			}
		}
		else //후보 이름이 나오지 않았다면 1로 초기화
		{	
			mp[name] = 1;
		}
	}

	cout << max << endl;	//가장 많은 표 출력
	for (const auto& element : mp)
	{
		if (element.second == max)	//가장 많은 표를 받은 후보자의 이름 출력
		{
			cout << element.first << " ";	//map 컨테이너는 자동으로 오름차순 정렬을 진행한다.
		}
	}
}