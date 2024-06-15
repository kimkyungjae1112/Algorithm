#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;	//좌석의 수와 색칠을 할 방법의 수
	cin >> N >> M;	//좌석 수, 색칠 방법 입력
	int* arrays = new int[N + 1];	//좌석을 나타내는 배열
	vector<int> vec(100, 0);	//좌석 색깔의 갯수를 나타내는 벡터

	for (int i = 1; i <= N; ++i)	//좌석은 첫번째부터 시작하므로 1부터 N까지
	{
		arrays[i] = 0;
	}

	for (int i = 0; i < M; ++i)	//좌석에 색깔을 칠하는 횟수
	{
		int start, end, color;	//왼쪽 번호, 오른쪽 번호, 색깔
		cin >> start >> end >> color;
		for (int j = start; j <= end; ++j)	//왼쪽 번호부터 오른쪽 번호까지 color를 계속 덮어 씌운다
		{
			arrays[j] = color;	//좌석에 색깔을 저장한다.
		}
	}

	for (int i = 1; i <= N; ++i)	//색깔의 갯수를 벡터의 인덱스로 표현한다.
	{
		vec[arrays[i]]++;
	}

	int max = -1;	//색깔은 총 100개 까지이므로 최솟값의 초기값은 100, 최댓값의 초기값은 -1로 설정해 반드시 바뀔 수 있도록 한다.
	int min = 100;

	int max_index = 0;	//인덱스 == 색깔의 번호 이므로 인덱스를 저장할 변수를 초기화한다.
	int min_index = 0;
	
	cout << endl;
	for (int i = 0; i < vec.size(); ++i)
	{
		//갯수가 같더라도 색의 번호가 더 작지 않으면 가장 많은 좌석이 칠해진 색의 번호를 바꾸지 않도록 한다.
		if (vec[i] > max || (vec[i] == vec[max_index] && i < max_index))	//최댓값을 찾기 위한 조건
		{
			max = vec[i];
			max_index = i;
		}
		if (vec[i] < min && vec[i] >= 1)	// 최솟값을 구하기 위한 조건, 색칠이 하나라도 있어야 하기에 >= 1 조건을 넣는다.
		{
			min = vec[i];
			min_index = i;
		}
	}

	cout << max_index << endl << min_index;	//마지막으로 인덱스 값을 출력한다.

	delete[] arrays; 
	return 0;
}