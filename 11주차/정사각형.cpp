#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

class Point2D	//�� ���� ���� �Ÿ��� �����ϴ� Ŭ����
{
public:
	int x, y, index;	//x, y ��ǥ���� ���° �׽�Ʈ ���̽��� ������ �����ϴ� index ����

	Point2D(int index, int x, int y) : index(index), x(x), y(y) {}	//������
	Point2D(int x, int y) : index(1), x(x), y(y) {}	//index�� �⺻���� 1�� �ʱ�ȭ�ϴ� ������

	long long getSquaredDistanceTo(Point2D target)
	{
		//�� ��ǥ���� �����Ÿ��� ����ϴ� �Լ�
		long long dx = abs(x - target.x);
		long long dy = abs(y - target.y);
		return dx * dx + dy * dy;
	}

	double getDistanceTo(Point2D target)
	{
		//�� ��ǥ���� �Ǽ� �Ÿ��� ����ϴ� �Լ�
		long long sqd = this->getSquaredDistanceTo(target);
		return sqrt(sqd);
	}

	bool operator<(const Point2D& other) const
	{
		//�� ��ǥ�� �켱������ ���ϱ� ���� �� ������

		//x ��ǥ�� �ٸ��ٸ� x��ǥ�� �������� ���Ѵ�.
		if (x != other.x)
			return x < other.x;
		//x ��ǥ�� ���ٸ� y��ǥ�� �������� ���Ѵ�.
		return y < other.y;
	}

};

long long getMaximumSquareArea(int n, const vector<Point2D>& points)
{
	long long answer = 0;

	//��� ���� set�� �����Ѵ�.
	set<Point2D> pSet;
	for (int i = 0; i < n; ++i)
	{
		pSet.insert(points[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		Point2D pa = points[i];
		for (int j = 0; j < n; ++j)
		{
			Point2D pb = points[j];

			if (i == j) continue;
			//�� ������ pa�� pb�� �����Ѵ�.
			//���� pa-pb�� ���簢���� �� ���̶�� ����.
		
			//�� ���� �Ÿ�(������ ����)�� ������ ���簢���� ���̰� �ȴ�.
			long long area = pa.getSquaredDistanceTo(pb);

			//�̹� ������ �簢������ ���̰� �۴ٸ� �ǳʶڴ�.
			if (area < answer)
				continue;

			//pa->pb ������ x,y ��ǥ�� ���� �Ÿ��� ���Ѵ�.
			int dx = pb.x - pa.x;
			int dy = pb.y - pa.y;

			//���� <dx, dy>�� 90���� ȸ����Ű�� <-dx, dy>�� �ȴ�.
			//pa�� pb�� ���� <-dy, dx>�� ���� ���� ���簢���� �����ϴ� �� �� pd,pc�� ����� �� �ִ�.
			Point2D pd(pa.x - dy, pa.y + dx);
			Point2D pc(pb.x - dy, pb.y + dx);

			//pd, pc�� �������̹Ƿ� �� ���� pSet�� �����ϴ� ������ �˻��ϸ� �ȴ�.
			if (pSet.count(pc) > 0 && pSet.count(pd) > 0) //O(log2N)
			{
				//if (pSet.find(pc) != pSet.end() && pSet.find(pd) != pSet.end()) 
				answer = max(answer, area);
			}
		}
	}

	return answer;
}

void process(int caseIndex)
{
	int n;	//n���� �� ����
	cin >> n;	//�� �Է�

	vector<Point2D> points;	//���� �����س��� ����

	for (int i = 0; i < n; ++i)	//n����ŭ ���� �Է��� �����Ѵ�.
	{
		int x, y;
		cin >> x >> y;
		points.push_back(Point2D(i, x, y));
	}

	long long answer = getMaximumSquareArea(n, points);	//�ִ�ũ�Ⱑ �� �� �ִ� ���簢���� ���̸� ���� ������ �����Ѵ�.
	cout << fixed << setprecision(2) << answer << endl;	//��� ����
}

int main()
{
	int caseSize;	//�׽�Ʈ ���̽� ����
	cin >> caseSize;	//�׽�Ʈ ���̽� �Է�

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)
	{
		process(caseIndex);	//�׽�Ʈ ���̽� ����ŭ ���� ����
	}
	return 0;
}
