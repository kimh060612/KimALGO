#include <iostream>
#include <fstream>
#include <algorithm>
#define INF 987654321
#define min(a, b) a > b ? b : a

using namespace std;

ifstream fin;
ofstream fout;

int N;
int DP[100001];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> N;

	fill(DP+1,DP+N+1,INF);
	DP[1] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j*j == i)DP[i] = 1;
			else if (i > j*j)
			{
				DP[i] = min(DP[i - (j*j)] + 1, DP[i]);
			}
			else break;
		}
	}

	cout << DP[N] << endl;

	fin.close();
	fout.close();
	return 0;
}