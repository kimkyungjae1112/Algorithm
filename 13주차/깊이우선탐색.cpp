#include <iostream> 
using namespace std;

int maps[10][10];     // 그래프의 인접 행렬을 저장할 배열
int visited[10] = { 0 }; // 방문 여부를 체크할 배열
int num;             // 간선의 수를 저장할 변수

// 그래프의 인접 행렬을 초기화하는 함수
void init()
{
    // 10x10 행렬의 모든 값을 0으로 초기화
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            maps[i][j] = 0;
        }
    }
}

// 깊이 우선 탐색(DFS)을 수행하는 함수
void dfs(int v)
{
    cout << v << endl;  // 현재 방문한 정점을 출력
    visited[v] = 0;     // 방문한 정점을 방문하지 않은 상태로 설정
    for (int i = 0; i <= num; ++i) // 모든 정점들을 탐색
    {
        if (maps[v][i] && visited[i]) // 인접하고 방문하지 않은 정점이 있다면
        {
            dfs(i); // 그 정점으로 DFS 재귀 호출
        }
    }
}

int main()
{
    int v1, v2; // 두 정점을 저장할 변수
    init();     // 그래프 초기화
    cin >> num; // 정점의 수를 입력 받음
    for (int i = 0; i < num; ++i) // 입력 받은 정점의 수만큼 반복
    {
        cin >> v1 >> v2; // 두 정점을 입력 받음
        maps[v1][v2] = maps[v2][v1] = 1; // 무방향 그래프이므로 양쪽 모두에 간선 설정
        visited[v1] = visited[v2] = 1; // 해당 정점을 방문하지 않은 상태로 설정
    }
    dfs(1); // 1번 정점에서 DFS 시작

    return 0; // 프로그램 종료
}