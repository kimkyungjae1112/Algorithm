#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<pair<int, int> > s;  //������ Ÿ������ pair<int, int> ���� �־��ش�. ž�� �ε����� ���̰� �� ���̴�.
    int num, height;    //ž�� ��, ž�� ����
    cin >> num; //ž�� �� �Է�

    for (int i = 0; i < num; i++)   //ž�� ����ŭ �ݺ�
    {
        cin >> height;  //ž�� ���� �Է�

        while (!s.empty())  //stack�� ž�� ������� ��
        {
            //����ž �߰����� �� �ش� ž�� �ε��� ���
            if (height < s.top().second)
            { 
                cout << s.top().first << " ";
                break;
            }
            //����ž ã�� ������ ��� pop
            s.pop();
        }
        
        //���� ž�� ���ٸ� 0 ���
        if (s.empty())
        {
            cout << 0 << " ";
        }

        //���� ž�� �ε����� ���̸� ���ÿ� Ǫ��
        s.push(make_pair(i + 1, height));
    }

    return 0;
}