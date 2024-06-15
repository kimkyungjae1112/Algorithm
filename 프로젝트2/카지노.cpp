#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool binary_search(const vector<int>& lotto, int target)	//������ ��÷��ȣ �� ���� ��ġ�ϸ� true�� ��ȯ�Ѵ�.
{
	int start = 0, end = lotto.size() - 1;	//�̺�Ž���� ���� �迭�� ù��°, ������ �ε����� �����س��´�.

	while (start <= end)	//�̺�Ž�� �˰�����, while ���� ����ߴ�. ù��° �ε����� ������ �ε������� �۰ų� ������������ Ž���Ѵ�.
	{
		int mid = (start + end) / 2;	//��� �ε����� �����ش�.

		if (lotto[mid] == target) return true;	//��� ��� ���� �츮�� ã�� ���� ���ٸ� true�� �����ϸ� �Լ� ����.

		if (lotto[mid] > target)	//��� ��� ���� ã�� ������ ũ�ٸ� ��� �ε��� �� -1 �� end�� �����Ѵ�.
		{
			end = mid - 1;
		}
		else if (lotto[mid] < target)	//��� ��� ���� ã�� ������ �۴ٸ� ��� �ε��� �� +1 �� start�� �����Ѵ�.
		{
			start = mid + 1;
		}
	}
	return false;	//��ã�Ҵٸ� false�� �����Ѵ�.
}

void sum_three_digit(const vector<int>& card, const vector<int>& lotto, set<int>& answer)  //����ڰ� �Է��� ī��� �� 3���� ī�带 ��� �����ִ� �Լ�
{
	int sum = 0;	//���ڸ� ���� ���� �ʱ�ȭ

	for (int j = 0; j < card.size(); ++j)
	{
		for (int k = 0; k < card.size(); ++k)
		{
			for (int l = 0; l < card.size(); ++l) //�� 3���� �ݺ����� 1,1,1 / 1,1,2 .... �̷������� ���ư��� 3���� ī�带 ���� �� �ֵ��� �Ѵ�.
			{
				sum = card[j] + card[k] + card[l];	//3���� ī�带 �̾� ���� ���Ѵ�.
				if (binary_search(lotto, sum))	//���� ���� ��÷��ȣ�� ���� ��ȣ�� �ִٸ� set�� �����Ѵ�.
				{
					answer.insert(sum);
				}
			}
		}
	}
}

int main()
{
	cout << "Hello World" << endl;
}