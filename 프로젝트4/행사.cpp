#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

// ����ư �Ÿ� ��� �Լ�
int manhattanDistance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    clock_t start, end; //���� �ð� ���� ����
    int N; // �׽�Ʈ ���̽� ����
    cin >> N; // �׽�Ʈ ���̽� �Է�

    vector<int> X(N); // x��ǥ�� ���� ����
    vector<int> Y(N); // y��ǥ�� ���� ����

    // �������� ���� ��ǥ�� �Է� ����
    for (int i = 0; i < N; ++i)
    {
        cin >> X[i] >> Y[i];
    }

    start = clock();    //���� ����
    // x ��ǥ�� �߰����� ã�´�
    sort(X.begin(), X.end());
    int medianX = X[N / 2];

    // y ��ǥ�� �߰����� ã�´�
    sort(Y.begin(), Y.end());
    int medianY = Y[N / 2];

    // �ּ� �̵� �Ÿ� �ʱ�ȭ
    int minDistance = INT_MAX;
    // ������ ��� ��� �ĺ� �ʱ�ȭ
    pair<int, int> optimalLocation;

    // ��� ��� ��� �ĺ��� ���� ���
    for (int i = 0; i < N; ++i)
    {
        // ���� �������� �� ��ǥ
        int x = X[i];
        int y = Y[i];
        // ���� �ĺ� ��� ��ҿ����� �̵� �Ÿ� �� �� ���
        int totalDistance = 0;
        for (int j = 0; j < N; ++j)
        {
            totalDistance += manhattanDistance(x, y, X[j], Y[j]);
        }
        // �̵� �Ÿ��� �� ���� �ּ��� ���, ������ ��� ��� �ĺ� ����
        if (totalDistance < minDistance)
        {
            minDistance = totalDistance;
            optimalLocation = { x, y };
        }
    }
    end = clock();  //���� ��

    double duration = (double)(end - start) / CLOCKS_PER_SEC;   //�ɸ� �ð� ���
    // ��� ����
    cout << optimalLocation.first << " " << optimalLocation.second << endl;
    cout << "����ð�: " << duration << '\n';

    return 0;
}