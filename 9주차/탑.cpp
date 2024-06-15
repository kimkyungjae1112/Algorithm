#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<pair<int, int> > s;  //스택의 타입으로 pair<int, int> 형을 넣어준다. 탑의 인덱스와 높이가 들어갈 것이다.
    int num, height;    //탑의 수, 탑의 높이
    cin >> num; //탑의 수 입력

    for (int i = 0; i < num; i++)   //탑의 수만큼 반복
    {
        cin >> height;  //탑의 높이 입력

        while (!s.empty())  //stack에 탑이 들어있을 때
        {
            //수신탑 발견했을 때 해당 탑의 인덱스 출력
            if (height < s.top().second)
            { 
                cout << s.top().first << " ";
                break;
            }
            //수신탑 찾을 때까지 계속 pop
            s.pop();
        }
        
        //수신 탑이 없다면 0 출력
        if (s.empty())
        {
            cout << 0 << " ";
        }

        //현재 탑의 인덱스와 높이를 스택에 푸쉬
        s.push(make_pair(i + 1, height));
    }

    return 0;
}