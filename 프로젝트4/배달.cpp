#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

// Function to find a unique sequence
void findUniqueSequence(int N, const vector<int>& D)
{
    set<vector<int>> validSequences;    //������ �������� �����ϴ� set

    //A1�� �� �� ������ ��� ���� �˻��Ѵ�.
    for (int A1 = 1; A1 <= N; ++A1)
    {
        vector<int> A(N);
        A[0] = A1;
        bool valid = true;

        //A2 - A1 = D1 �̹Ƿ�  A2 = A1 + D1 ���� ���� �� �ִ�.
        for (int i = 1; i < N; ++i)
        {
            A[i] = A[i - 1] + D[i - 1];
            if (A[i] < 1 || A[i] > N)   //A�� 1 ~ N ������ ���� �����Ƿ� �� ���� ���� ������ A1������ �ٽ� ���Ѵ�.
            {
                valid = false;  //vaild�� false�� ���������ν� �������� �����ϴ� set�� �������� �ʴ´�.
                break;  //�ش� A1 ������ �����ϴ� �������� �����Ѵ�.
            }
        }

        //���� �ݺ����� ����� ��� �ش� �������� set�� �����Ѵ�.
        if (valid)
        {
            validSequences.insert(A);
        }
    }


    if (validSequences.size() == 1) //���� ������ A �������� �ִٸ� �� ���� ����Ѵ�.
    {
        for (int x : *validSequences.begin())
        {
            cout << x << " ";
        }
        cout << endl;
    }
    else  //�������� ���ų� �ߺ��ȴٸ� -1�� ����Ѵ�.
    {
        cout << -1 << endl;
    }
}

int main()
{
    int N;  //������ ����
    cin >> N;   //���� ��ȣ �Է�
    vector<int> D(N - 1);   //D ������ ���� ����
    clock_t start, end; //�ð� ����
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> D[i];    //D ������ �Է�
    }

    start = clock();    //�ð� ����
    findUniqueSequence(N, D);
    end = clock();

    //����ð� ���
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("����ð� : %lf��", duration);

    return 0;
}