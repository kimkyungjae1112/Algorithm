#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;	//승철이가 본 에피소드의 수
	cin >> n;	//에피소드의 수 입력
	vector<int> vec;	//에피소드의 번호를 저장할 저장소

	for (int i = 0; i < n; ++i)	//에피소드의 수 만큼 에피소드의 번호를 저장한다.
	{
		int a;
		cin >> a;
		vec.push_back(a);	//vector 컨테이너에 있는 멤버 함수 push_back, 컨테이너의 끝에 원소를 삽입한다.
	}

	sort(vec.begin(), vec.end());	//algorithm 라이브러리에 정의된 함수, 컨테이너의 정렬을 도와준다.
									//오름차순으로 정렬을 진행한다.
	for (int i = 0; i < n - 1; ++i)
	{
		if (vec[i + 1] - vec[i] > 1)	//에피소드 번호는 오름차순으로 정렬되어있다. 따라서 뒤의 에피소드 번호와 앞의 에피소드 번호의 차이가 1을 초과한다면 수열이 아니다.
		{
			cout << "NO";	//NO를 출력하고 프로그램을 끝낸다.
			return 0;
		}
	}
	cout << "YES";	//앞선 반복문에서 걸리지 않았다면 에피소드 번호의 차이가 1이란 소리기 때문에 YES를 출력한다.
	return 0;
}