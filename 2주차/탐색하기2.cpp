#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	string str;
	vector<int> Indexs;

	for (int i = 0; i < N; ++i)
	{
		cin >> str;

		if (str == "AJOU")	
		{
			Indexs.push_back(i + 1);
		}
	}

	cout << *(Indexs.begin()) << " " << *(Indexs.end() - 1) << '\n';
	return 0;
}