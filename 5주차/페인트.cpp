#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;	//�¼��� ���� ��ĥ�� �� ����� ��
	cin >> N >> M;	//�¼� ��, ��ĥ ��� �Է�
	int* arrays = new int[N + 1];	//�¼��� ��Ÿ���� �迭
	vector<int> vec(100, 0);	//�¼� ������ ������ ��Ÿ���� ����

	for (int i = 1; i <= N; ++i)	//�¼��� ù��°���� �����ϹǷ� 1���� N����
	{
		arrays[i] = 0;
	}

	for (int i = 0; i < M; ++i)	//�¼��� ������ ĥ�ϴ� Ƚ��
	{
		int start, end, color;	//���� ��ȣ, ������ ��ȣ, ����
		cin >> start >> end >> color;
		for (int j = start; j <= end; ++j)	//���� ��ȣ���� ������ ��ȣ���� color�� ��� ���� �����
		{
			arrays[j] = color;	//�¼��� ������ �����Ѵ�.
		}
	}

	for (int i = 1; i <= N; ++i)	//������ ������ ������ �ε����� ǥ���Ѵ�.
	{
		vec[arrays[i]]++;
	}

	int max = -1;	//������ �� 100�� �����̹Ƿ� �ּڰ��� �ʱⰪ�� 100, �ִ��� �ʱⰪ�� -1�� ������ �ݵ�� �ٲ� �� �ֵ��� �Ѵ�.
	int min = 100;

	int max_index = 0;	//�ε��� == ������ ��ȣ �̹Ƿ� �ε����� ������ ������ �ʱ�ȭ�Ѵ�.
	int min_index = 0;
	
	cout << endl;
	for (int i = 0; i < vec.size(); ++i)
	{
		//������ ������ ���� ��ȣ�� �� ���� ������ ���� ���� �¼��� ĥ���� ���� ��ȣ�� �ٲ��� �ʵ��� �Ѵ�.
		if (vec[i] > max || (vec[i] == vec[max_index] && i < max_index))	//�ִ��� ã�� ���� ����
		{
			max = vec[i];
			max_index = i;
		}
		if (vec[i] < min && vec[i] >= 1)	// �ּڰ��� ���ϱ� ���� ����, ��ĥ�� �ϳ��� �־�� �ϱ⿡ >= 1 ������ �ִ´�.
		{
			min = vec[i];
			min_index = i;
		}
	}

	cout << max_index << endl << min_index;	//���������� �ε��� ���� ����Ѵ�.

	delete[] arrays; 
	return 0;
}