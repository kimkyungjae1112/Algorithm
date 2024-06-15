#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

// Function to find a unique sequence
void findUniqueSequence(int N, const vector<int>& D)
{
    set<vector<int>> validSequences;    //가능한 시퀀스를 저장하는 set

    //A1의 값 중 가능한 모든 값을 검사한다.
    for (int A1 = 1; A1 <= N; ++A1)
    {
        vector<int> A(N);
        A[0] = A1;
        bool valid = true;

        //A2 - A1 = D1 이므로  A2 = A1 + D1 식을 만들 수 있다.
        for (int i = 1; i < N; ++i)
        {
            A[i] = A[i - 1] + D[i - 1];
            if (A[i] < 1 || A[i] > N)   //A는 1 ~ N 까지의 값을 가지므로 이 외의 값이 나오면 A1값부터 다시 구한다.
            {
                valid = false;  //vaild를 false로 설정함으로써 시퀀스를 저장하는 set에 삽입하지 않는다.
                break;  //해당 A1 값으로 시작하는 시퀀스를 제외한다.
            }
        }

        //위의 반복문을 통과한 경우 해당 시퀀스를 set에 삽입한다.
        if (valid)
        {
            validSequences.insert(A);
        }
    }


    if (validSequences.size() == 1) //만약 유일한 A 시퀀스가 있다면 그 값을 출력한다.
    {
        for (int x : *validSequences.begin())
        {
            cout << x << " ";
        }
        cout << endl;
    }
    else  //시퀀스가 없거나 중복된다면 -1을 출력한다.
    {
        cout << -1 << endl;
    }
}

int main()
{
    int N;  //소포의 갯수
    cin >> N;   //소포 번호 입력
    vector<int> D(N - 1);   //D 시퀀스 벡터 변수
    clock_t start, end; //시간 변수
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> D[i];    //D 시퀀스 입력
    }

    start = clock();    //시간 측정
    findUniqueSequence(N, D);
    end = clock();

    //실행시간 출력
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("실행시간 : %lf초", duration);

    return 0;
}