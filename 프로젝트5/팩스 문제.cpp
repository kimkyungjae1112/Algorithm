//소프트웨어공학과 200765 김경재 프로젝트_V 소스코드
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <ctime>

using namespace std;

const vector<int> Levels = { 1, 86, 172, 256 }; // 변환 레벨
const vector<string> Codes = { "00", "01", "10", "11" }; // 각 레벨에 대한 2비트 코드

int main()
{
    int N, W;
    cin >> N >> W; // 수열의 길이와 가중치 입력
    clock_t Start, End; //시간 변수

    vector<int> Sequences(N);   //입력 수열을 저장할 벡터
    for (int i = 0; i < N; i++)
    {
        cin >> Sequences[i]; // 수열 입력
    }

    Start = clock();
    // DP 테이블 초기화 (최소 비용을 저장)
    vector<vector<long long>> Dp(N, vector<long long>(4, LLONG_MAX));
    // 이전 인덱스를 저장 (경로 추적용)
    vector<vector<int>> Prev(N, vector<int>(4, -1));

    // 초기값 설정: 첫 번째 수에 대해 각 레벨로 변환했을 때의 에러
    for (int j = 0; j < 4; j++)
    {
        Dp[0][j] = abs(Sequences[0] - Levels[j]); // 첫 번째 수와 각 레벨 간의 에러 저장
    }

    // DP 계산: 두 번째 수부터 마지막 수까지 처리
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        { // 현재 레벨
            for (int k = 0; k < 4; k++)
            { // 이전 레벨
                long long Error = abs(Sequences[i] - Levels[j]); // 현재 수와 변환 레벨 간의 에러
                long long CodeCost = (j != k) ? 3 : 1; // 이전 레벨과 다르면 3비트 추가, 같으면 1비트 추가
                long long Cost = Dp[i - 1][k] + Error + CodeCost * W; // 총 비용 계산
                if (Cost < Dp[i][j])
                { // 최소 비용 갱신
                    Dp[i][j] = Cost;
                    Prev[i][j] = k; // 이전 인덱스 저장
                }
            }
        }
    }

    // 최소 비용 찾기 (마지막 수에서)
    long long MinCost = LLONG_MAX; // 최소 비용을 저장할 변수, 초기값은 가능한 최대 값으로 설정
    int LastIndex = -1; // 최소 비용을 가지는 레벨의 인덱스를 저장할 변수, 초기값은 -1
    for (int j = 0; j < 4; j++) // 4개의 레벨을 순회
    {
        if (Dp[N - 1][j] < MinCost) // 마지막 수(N-1)를 j번째 레벨로 변환했을 때의 비용이 현재 저장된 MinCost보다 작은지 확인
        {
            MinCost = Dp[N - 1][j]; // 더 작은 비용을 찾으면 MinCost를 갱신
            LastIndex = j; // 해당 레벨의 인덱스를 LastIndex에 저장
        }
    }

    // 변환된 수열 복원
    vector<int> ConvertedSequences(N);  // 변환될 수열을 저장할 벡터
    int Index = LastIndex;
    for (int i = N - 1; i >= 0; i--)
    {
        ConvertedSequences[i] = Levels[Index]; // 변환된 수열을 저장
        if (i != 0) Index = Prev[i][Index]; // 이전 인덱스로 이동
    }

    // 변환 코드 생성
    string Code;
    // 첫 번째 수의 레벨 인덱스 찾기
    int prev_level = find(Levels.begin(), Levels.end(), ConvertedSequences[0]) - Levels.begin();
    Code += Codes[prev_level]; // 첫 번째 수의 코드값
    for (int i = 1; i < N; i++)
    {
        int current_level = find(Levels.begin(), Levels.end(), ConvertedSequences[i]) - Levels.begin();
        if (current_level == prev_level)
        {
            Code += "0"; // 이전 수와 같은 경우 0을 추가
        }
        else
        {
            Code += "1" + Codes[current_level]; // 이전 수와 다른 경우 1을 추가하고 새로운 코드 추가
        }
        prev_level = current_level; // 이전 레벨 인덱스를 현재 레벨 인덱스로 갱신
    }

    // 최종 비용 계산
    long long FinalError = 0;
    for (int i = 0; i < N; i++)
    {
        FinalError += abs(Sequences[i] - ConvertedSequences[i]); // 전체 에러 계산
    }
    long long FinalCost = FinalError + W * Code.length(); // 최종 비용 계산 (에러 + 코드 길이 * 가중치)

    End = clock();

    // 출력
    cout << FinalCost << endl;
    cout << Code << endl;

    //실행시간 출력
    double duration = (double)(End - Start) / CLOCKS_PER_SEC;
    printf("실행시간 : %lf초", duration);

    return 0;
}