#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N;	//데이터 수 
	cin >> N;	//데이터 수 입력
	set<int> st;	//자동으로 중복 제거 및 오름차순으로 정렬해주는 set 사용

	for (int i = 0; i < N; ++i)	//set에 데이터 입력
	{
		int a;
		cin >> a;
		st.insert(a);
	}

	set<int>::iterator iter = st.begin();	//set을 순회하기 위한 반복자
	while (iter != st.end())	//컨테이너의 전체를 순회하는 반복문
	{
		cout << *iter << " ";	//컨테이너 안의 요소를 출력 및 공백
		iter++;	//하나씩 옮겨간다.
	}
	return 0;
}