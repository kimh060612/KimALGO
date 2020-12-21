#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define INF 1001

using namespace std;

ifstream fin;
ofstream fout;

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int N;
	vector<int> A;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		if (A.empty() || A.back() < a)
		{
			A.push_back(a);
		}
		else
		{
			auto it = lower_bound(A.begin(), A.end(), a);
			*it = a;
		}

	}

	cout << A.size() << endl;

	fin.close();
	fout.close();
	return 0;
}
