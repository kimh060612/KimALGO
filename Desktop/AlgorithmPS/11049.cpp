#include <iostream>
#include <fstream>
#include <vector>
#define min(a, b) a > b ? b : a 
#define INF 501

using namespace std;

ifstream fin;
ofstream fout;

int n;

int ROW[INF], COL[INF];
int DP[INF][INF];

int ORDER(int s, int e)
{

	if (s == e || s > e)return 0;

	int &ret = DP[s][e];
	if (ret != 0)return ret;

	ret = 987654321;

	for (int i = s; i <= e; i++)
	{
		ret = min(ret, ORDER(s, i) + ORDER(i + 1, e) + ROW[s] * COL[i] * COL[e]);
	}

	return ret;

}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> ROW[i] >> COL[i];
	}

	cout << ORDER(1, n) << endl;
	return 0;
}