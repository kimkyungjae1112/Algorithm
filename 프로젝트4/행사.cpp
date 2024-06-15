#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

// 맨하튼 거리 계산 함수
int manhattanDistance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    clock_t start, end; //수행 시간 층적 변수
    int N; // 테스트 케이스 변수
    cin >> N; // 테스트 케이스 입력

    vector<int> X(N); // x좌표를 담을 벡터
    vector<int> Y(N); // y좌표를 담을 벡터

    // 참가자의 집의 좌표를 입력 받음
    for (int i = 0; i < N; ++i)
    {
        cin >> X[i] >> Y[i];
    }

    start = clock();    //로직 시작
    // x 좌표의 중간값을 찾는다
    sort(X.begin(), X.end());
    int medianX = X[N / 2];

    // y 좌표의 중간값을 찾는다
    sort(Y.begin(), Y.end());
    int medianY = Y[N / 2];

    // 최소 이동 거리 초기화
    int minDistance = INT_MAX;
    // 최적의 행사 장소 후보 초기화
    pair<int, int> optimalLocation;

    // 모든 행사 장소 후보에 대해 계산
    for (int i = 0; i < N; ++i)
    {
        // 현재 참가자의 집 좌표
        int x = X[i];
        int y = Y[i];
        // 현재 후보 행사 장소에서의 이동 거리 총 합 계산
        int totalDistance = 0;
        for (int j = 0; j < N; ++j)
        {
            totalDistance += manhattanDistance(x, y, X[j], Y[j]);
        }
        // 이동 거리의 총 합이 최소인 경우, 최적의 행사 장소 후보 갱신
        if (totalDistance < minDistance)
        {
            minDistance = totalDistance;
            optimalLocation = { x, y };
        }
    }
    end = clock();  //로직 끝

    double duration = (double)(end - start) / CLOCKS_PER_SEC;   //걸린 시간 계산
    // 출력 형식
    cout << optimalLocation.first << " " << optimalLocation.second << endl;
    cout << "실행시간: " << duration << '\n';

    return 0;
}