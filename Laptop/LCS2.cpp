#include <iostream>
#include <string>
#define INF 1001

using namespace std;

string S1, S2;
int N1, N2;
int DP[INF][INF];

int main()
{
	cin >> S1 >> S2;
	N1 = S1.length();
	N2 = S2.length();

	for (int i = 1; i <= N1; i++)
	{
		for (int j = 1; j <= N2; j++)
		{
			if (S1.at(i - 1) == S2.at(j - 1)) DP[i][j] = DP[i - 1][j - 1] + 1;
			else DP[i][j] = DP[i - 1][j] > DP[i][j - 1] ? DP[i - 1][j] : DP[i][j - 1];
		}
	}

	int i = N1;
	int j = N2;
	string res = "";

	while (DP[i][j] != 0)
	{
		if (DP[i][j] == DP[i - 1][j]) i--;
		else if (DP[i][j] == DP[i][j - 1]) j--;
		else
		{
			res = S1.at(i-1) + res;
			i --;
			j--;
		}
	}

	cout << DP[N1][N2] << endl;
	cout << res << endl;

	return 0;
}