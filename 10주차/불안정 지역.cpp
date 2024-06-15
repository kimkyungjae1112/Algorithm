#include <iostream>
#include <queue>
using namespace std;

int Min(queue<int> q)   //�ش� ť�� K������ŭ������ �ּڰ��� ���ϴ� �Լ�
{
    int min = 1000000001;   //10�� ������ �ڿ����� �ּڰ� �⺻ ������ 1 ���� �����Ѵ�.
    while (!q.empty())  //ť�� �������� �ݺ��Ѵ�.
    {
        if (min > q.front())    //q�� ���� �ּڰ����� �۴ٸ�
        {
            min = q.front();    //�ּڰ��� q�� ġȯ�Ѵ�.
        }
        q.pop();    //q�� ��� ������� �����Ѵ�.
    }
    return min; //���� �ּڰ��� ��ȯ�Ѵ�.
}

int Max(queue<int> q)   //�ش� ť�� K������ŭ������ �ִ��� ���ϴ� �Լ�
{
    int max = -1;   //0���ͱ� ������ �ִ��� �⺻ ������ -1�� �Ѵ�.
    queue<int> temp = q;    //q�� �ٽ� Min �Լ��� �Ѱ��ٰ��̱� ������, �����ؼ� �Ѱ��� q�� �ǵ����� �ʴ´�.
    while (!temp.empty())   //ť�� �������� �ݺ��Ѵ�.
    {
        if (max < temp.front()) //q�� ���� �ִ񰪺��� ũ�ٸ�
        {
            max = temp.front(); //�ִ��� q�� ġȯ�Ѵ�.
        }
        temp.pop(); //temp�� ��� ������� �����Ѵ�.
    }
    return max - Min(q);    //�ִ� - �ּڰ��� ����ؼ� ��ȯ���ش�.
}

int main()
{
    int T;  //�׽�Ʈ ���̽� ����
    cin >> T;   //�׽�Ʈ ���̽� �Է�
    int* answer = new int[T];   //������ ������ �迭

    for (int i = 0; i < T; ++i) //�׽�Ʈ ���̽� ����ŭ �ݺ�
    {
        int N, K;   //���� ���� ���� ����
        cin >> N >> K;  //N�� K �Է�

        queue<int> q;   //ó�� �Է¹��� q
        queue<int> q2;  //k ����ŭ ����ְ� �� q

        int max = -1;   //�ִ� �ʱⰪ

        for (int j = 0; j < N; ++j) //q�� ���� �ҵ� ���� �ο�
        {
            int income;
            cin >> income;
            q.push(income);
        }

        int count = 0;  //k�� ���� ����

        while (!q.empty())  //q�� �������� �ݺ�
        {
            q2.push(q.front()); //q�� ����ִ� ���� q2�� �ű��.
            q.pop();    //q���� �Ű����� q������ �����.
            ++count;    //count�� �ϳ��� ������Ų��.

            if (count >= K) //count���� K���� ���ų� Ŀ���� ���� �������� �ִ� - �ּڰ��� ����Ѵ�.
            {
                if (max < Max(q2))  //Max�Լ����� ���� ���� ������ max�� ���ϸ� ġȯ�Ѵ�.
                {
                    max = Max(q2);
                }
                q2.pop();   //q2���� ����� �Ϸ�Ǹ� �� ���� ���ô� ����� �ٽ� ���ο� ���ø� �޾� �ҵ� ������ ����Ѵ�.
            }
        }
        answer[i] = max;    //���� ���� �迭�� �ִ´�.
    }
    for (int i = 0; i < T; ++i) //��� ����
    {
        printf("%d\n", answer[i]);
    }

    delete[] answer;    //�޸� ��ȯ
    return 0;
}