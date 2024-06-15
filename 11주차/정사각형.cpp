#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

class Point2D	//두 점과 사이 거리를 연산하는 클래스
{
public:
	int x, y, index;	//x, y 좌표값과 몇번째 테스트 케이스의 변인지 구별하는 index 변수

	Point2D(int index, int x, int y) : index(index), x(x), y(y) {}	//생성자
	Point2D(int x, int y) : index(1), x(x), y(y) {}	//index를 기본으로 1로 초기화하는 생성자

	long long getSquaredDistanceTo(Point2D target)
	{
		//두 좌표간의 제곱거리를 계산하는 함수
		long long dx = abs(x - target.x);
		long long dy = abs(y - target.y);
		return dx * dx + dy * dy;
	}

	double getDistanceTo(Point2D target)
	{
		//두 좌표간의 실수 거리를 계산하는 함수
		long long sqd = this->getSquaredDistanceTo(target);
		return sqrt(sqd);
	}

	bool operator<(const Point2D& other) const
	{
		//각 좌표의 우선순위를 비교하기 위한 비교 연산자

		//x 좌표가 다르다면 x좌표를 기준으로 비교한다.
		if (x != other.x)
			return x < other.x;
		//x 좌표가 같다면 y좌표를 기준으로 비교한다.
		return y < other.y;
	}

};

long long getMaximumSquareArea(int n, const vector<Point2D>& points)
{
	long long answer = 0;

	//모든 점을 set에 저장한다.
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
			//두 기준점 pa와 pb를 지정한다.
			//선분 pa-pb가 정사각형의 한 변이라고 하자.
		
			//두 점의 거리(선분의 길이)의 제곱은 정사각형의 넓이가 된다.
			long long area = pa.getSquaredDistanceTo(pb);

			//이미 구현한 사각형보다 넓이가 작다면 건너뛴다.
			if (area < answer)
				continue;

			//pa->pb 방향의 x,y 좌표에 대한 거리를 구한다.
			int dx = pb.x - pa.x;
			int dy = pb.y - pa.y;

			//벡터 <dx, dy>를 90도로 회전시키면 <-dx, dy>가 된다.
			//pa와 pb에 벡터 <-dy, dx>를 각각 더해 정사각형을 구성하는 두 점 pd,pc를 계산할 수 있다.
			Point2D pd(pa.x - dy, pa.y + dx);
			Point2D pc(pb.x - dy, pb.y + dx);

			//pd, pc가 결정적이므로 이 점이 pSet에 존재하는 점인지 검사하면 된다.
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
	int n;	//n개의 점 변수
	cin >> n;	//점 입력

	vector<Point2D> points;	//점을 보관해놓을 벡터

	for (int i = 0; i < n; ++i)	//n번만큼 점을 입력해 보관한다.
	{
		int x, y;
		cin >> x >> y;
		points.push_back(Point2D(i, x, y));
	}

	long long answer = getMaximumSquareArea(n, points);	//최대크기가 될 수 있는 정사각형의 넓이를 구해 변수에 대입한다.
	cout << fixed << setprecision(2) << answer << endl;	//출력 형식
}

int main()
{
	int caseSize;	//테스트 케이스 변수
	cin >> caseSize;	//테스트 케이스 입력

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)
	{
		process(caseIndex);	//테스트 케이스 수만큼 로직 실행
	}
	return 0;
}
