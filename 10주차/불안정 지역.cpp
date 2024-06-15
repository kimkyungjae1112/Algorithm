#include <iostream>
#include <queue>
using namespace std;

int Min(queue<int> q)   //해당 큐의 K범위만큼에서의 최솟값을 구하는 함수
{
    int min = 1000000001;   //10억 이하의 자연수니 최솟값 기본 설정을 1 높은 수로한다.
    while (!q.empty())  //큐가 빌때까지 반복한다.
    {
        if (min > q.front())    //q의 값이 최솟값보다 작다면
        {
            min = q.front();    //최솟값을 q로 치환한다.
        }
        q.pop();    //q를 계속 비워가며 조사한다.
    }
    return min; //구한 최솟값을 반환한다.
}

int Max(queue<int> q)   //해당 큐의 K범위만큼에서의 최댓값을 구하는 함수
{
    int max = -1;   //0부터기 때문에 최댓값의 기본 설정을 -1로 한다.
    queue<int> temp = q;    //q를 다시 Min 함수에 넘겨줄것이기 때문에, 복사해서 넘겨줄 q를 건들이지 않는다.
    while (!temp.empty())   //큐가 빌때까지 반복한다.
    {
        if (max < temp.front()) //q의 값이 최댓값보다 크다면
        {
            max = temp.front(); //최댓값을 q로 치환한다.
        }
        temp.pop(); //temp를 계속 비워가며 조사한다.
    }
    return max - Min(q);    //최댓값 - 최솟값을 계산해서 반환해준다.
}

int main()
{
    int T;  //테스트 케이스 변수
    cin >> T;   //테스트 케이스 입력
    int* answer = new int[T];   //정답을 저장할 배열

    for (int i = 0; i < T; ++i) //테스트 케이스 수만큼 반복
    {
        int N, K;   //도시 수와 영역 변수
        cin >> N >> K;  //N과 K 입력

        queue<int> q;   //처음 입력받을 q
        queue<int> q2;  //k 수만큼 들어있게 할 q

        int max = -1;   //최댓값 초기값

        for (int j = 0; j < N; ++j) //q에 도시 소득 수준 부여
        {
            int income;
            cin >> income;
            q.push(income);
        }

        int count = 0;  //k와 비교할 변수

        while (!q.empty())  //q가 빌때까지 반복
        {
            q2.push(q.front()); //q에 들어있는 값을 q2로 옮긴다.
            q.pop();    //q에서 옮겼으면 q에서는 지운다.
            ++count;    //count를 하나씩 증가시킨다.

            if (count >= K) //count값이 K보다 같거나 커지면 이제 영역별로 최댓값 - 최솟값을 계산한다.
            {
                if (max < Max(q2))  //Max함수에서 나온 수와 기존의 max를 비교하며 치환한다.
                {
                    max = Max(q2);
                }
                q2.pop();   //q2에서 계산이 완료되면 젤 왼쪽 도시는 지우고 다시 새로운 도시를 받아 소득 수준을 계산한다.
            }
        }
        answer[i] = max;    //나온 값을 배열에 넣는다.
    }
    for (int i = 0; i < T; ++i) //출력 형식
    {
        printf("%d\n", answer[i]);
    }

    delete[] answer;    //메모리 반환
    return 0;
}