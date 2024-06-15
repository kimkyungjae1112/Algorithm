//����Ʈ������а� 200765 ����� ������Ʈ_V �ҽ��ڵ�
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <ctime>

using namespace std;

const vector<int> Levels = { 1, 86, 172, 256 }; // ��ȯ ����
const vector<string> Codes = { "00", "01", "10", "11" }; // �� ������ ���� 2��Ʈ �ڵ�

int main()
{
    int N, W;
    cin >> N >> W; // ������ ���̿� ����ġ �Է�
    clock_t Start, End; //�ð� ����

    vector<int> Sequences(N);   //�Է� ������ ������ ����
    for (int i = 0; i < N; i++)
    {
        cin >> Sequences[i]; // ���� �Է�
    }

    Start = clock();
    // DP ���̺� �ʱ�ȭ (�ּ� ����� ����)
    vector<vector<long long>> Dp(N, vector<long long>(4, LLONG_MAX));
    // ���� �ε����� ���� (��� ������)
    vector<vector<int>> Prev(N, vector<int>(4, -1));

    // �ʱⰪ ����: ù ��° ���� ���� �� ������ ��ȯ���� ���� ����
    for (int j = 0; j < 4; j++)
    {
        Dp[0][j] = abs(Sequences[0] - Levels[j]); // ù ��° ���� �� ���� ���� ���� ����
    }

    // DP ���: �� ��° ������ ������ ������ ó��
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        { // ���� ����
            for (int k = 0; k < 4; k++)
            { // ���� ����
                long long Error = abs(Sequences[i] - Levels[j]); // ���� ���� ��ȯ ���� ���� ����
                long long CodeCost = (j != k) ? 3 : 1; // ���� ������ �ٸ��� 3��Ʈ �߰�, ������ 1��Ʈ �߰�
                long long Cost = Dp[i - 1][k] + Error + CodeCost * W; // �� ��� ���
                if (Cost < Dp[i][j])
                { // �ּ� ��� ����
                    Dp[i][j] = Cost;
                    Prev[i][j] = k; // ���� �ε��� ����
                }
            }
        }
    }

    // �ּ� ��� ã�� (������ ������)
    long long MinCost = LLONG_MAX; // �ּ� ����� ������ ����, �ʱⰪ�� ������ �ִ� ������ ����
    int LastIndex = -1; // �ּ� ����� ������ ������ �ε����� ������ ����, �ʱⰪ�� -1
    for (int j = 0; j < 4; j++) // 4���� ������ ��ȸ
    {
        if (Dp[N - 1][j] < MinCost) // ������ ��(N-1)�� j��° ������ ��ȯ���� ���� ����� ���� ����� MinCost���� ������ Ȯ��
        {
            MinCost = Dp[N - 1][j]; // �� ���� ����� ã���� MinCost�� ����
            LastIndex = j; // �ش� ������ �ε����� LastIndex�� ����
        }
    }

    // ��ȯ�� ���� ����
    vector<int> ConvertedSequences(N);  // ��ȯ�� ������ ������ ����
    int Index = LastIndex;
    for (int i = N - 1; i >= 0; i--)
    {
        ConvertedSequences[i] = Levels[Index]; // ��ȯ�� ������ ����
        if (i != 0) Index = Prev[i][Index]; // ���� �ε����� �̵�
    }

    // ��ȯ �ڵ� ����
    string Code;
    // ù ��° ���� ���� �ε��� ã��
    int prev_level = find(Levels.begin(), Levels.end(), ConvertedSequences[0]) - Levels.begin();
    Code += Codes[prev_level]; // ù ��° ���� �ڵ尪
    for (int i = 1; i < N; i++)
    {
        int current_level = find(Levels.begin(), Levels.end(), ConvertedSequences[i]) - Levels.begin();
        if (current_level == prev_level)
        {
            Code += "0"; // ���� ���� ���� ��� 0�� �߰�
        }
        else
        {
            Code += "1" + Codes[current_level]; // ���� ���� �ٸ� ��� 1�� �߰��ϰ� ���ο� �ڵ� �߰�
        }
        prev_level = current_level; // ���� ���� �ε����� ���� ���� �ε����� ����
    }

    // ���� ��� ���
    long long FinalError = 0;
    for (int i = 0; i < N; i++)
    {
        FinalError += abs(Sequences[i] - ConvertedSequences[i]); // ��ü ���� ���
    }
    long long FinalCost = FinalError + W * Code.length(); // ���� ��� ��� (���� + �ڵ� ���� * ����ġ)

    End = clock();

    // ���
    cout << FinalCost << endl;
    cout << Code << endl;

    //����ð� ���
    double duration = (double)(End - Start) / CLOCKS_PER_SEC;
    printf("����ð� : %lf��", duration);

    return 0;
}