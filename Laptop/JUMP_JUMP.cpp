#include <iostream>
#include <fstream>
#include <algorithm>
#define min(a,b) a > b ?  b : a
#define INF 987654321

using namespace std;

ifstream fin;
ofstream fout;

int A[1001], n;
int DP[1001];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	fill(DP + 1, DP + n + 1, INF);

	DP[1] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= i + A[i] && j <= n; j++)
		{
			DP[j] = min(DP[j], DP[i] + 1);
		}
	}

	if (DP[n] == INF) cout << "-1" << endl;
	else cout << DP[n] << endl;

	fin.close();
	fout.close();
}