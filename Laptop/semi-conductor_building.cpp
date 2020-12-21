#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define INF -987654321

using namespace std;

ifstream fin;
ofstream fout;

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	vector<int> A;
	int n, ans = 0;
	cin >> n;
	A.push_back(INF);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (A.back() < x)
		{
			A.push_back(x);
			ans++;
		}
		else
		{
			auto it = lower_bound(A.begin(), A.end(), x);
			*it = x;
		}
	}

	cout << ans << endl;

	fin.close();
	fout.close();
}