#include <iostream>
#include <fstream>
#define MAX 101
#define INF 100001
#define min(a,b) a > b ? b : a

using namespace std;

ifstream fin;
ofstream fout;

int N, K;
int coin[MAX];
int DP[10001];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> coin[i];
	}

	for (int i = 0; i <= K; i++)DP[i] = INF;

	DP[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if(j >= coin[i])DP[j] = min(DP[j],DP[j-coin[i]]+1);
		}
	}

	if (DP[K] == INF)cout << -1 << endl;
	else cout << DP[K] << endl;

	fin.close();
	fout.close();
	return 0;
}