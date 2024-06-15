#include <iostream>  
#include <queue>    
using namespace std;

int map[10][10] = { 0 }; // 그래프의 인접 행렬을 저장할 배열
int visit[10] = { 0 };   // 방문 여부를 체크할 배열
queue<int> q;            // BFS를 위한 큐
int num, edge_num;       // 정점의 수와 간선의 수를 저장할 변수

// 너비 우선 탐색(BFS)을 수행하는 함수
void bfs(int v)
{
    cout << v << '\n'; // 현재 방문한 정점을 출력
    q.push(v);         // 시작 정점을 큐에 추가
    while (!q.empty()) // 큐가 비어있지 않은 동안 반복
    {
        int node = q.front(); // 큐의 앞쪽 정점을 가져옴
        q.pop();              // 큐에서 해당 정점을 제거
        for (int i = 0; i <= num; i++) // 모든 정점들을 탐색
        {
            if (map[node][i] == 1 && visit[i] == 0) // 인접하고 방문하지 않은 정점이 있다면
            {
                visit[node] = 1; // 현재 정점을 방문한 상태로 설정
                visit[i] = 1;    // 인접한 정점을 방문한 상태로 설정
                cout << i << endl; // 인접한 정점을 출력
                q.push(i);       // 인접한 정점을 큐에 추가
            }
        }
    }
}

int main()
{
    cin >> num >> edge_num; // 정점의 수와 간선의 수를 입력 받음
    for (int i = 0; i < edge_num; ++i) // 입력 받은 간선의 수만큼 반복
    {
        int v1, v2;
        cin >> v1 >> v2; // 두 정점을 입력 받음
        map[v1][v2] = map[v2][v1] = 1; // 무방향 그래프이므로 양쪽 모두에 간선 설정
    }
    bfs(1); // 1번 정점에서 BFS 시작
    return 0; // 프로그램 종료
}