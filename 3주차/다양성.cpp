#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> Set;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int a;
		cin >> a;
		Set.insert(a);
	}
	cout << Set.size();
	return 0;
}