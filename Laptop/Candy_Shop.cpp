#include <iostream>
#include <memory.h>
#define EPS 0.001

using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int DP[10001]; //불편하지만 어쩔 수 없다

int main()
{
	while (1)
	{
		memset(DP, 0 ,sizeof(DP));
		int n, money;
		double m;
		cin >> n >> m;
		if (n == 0 && m < EPS)break;
		money = (int)(m * 100 + 0.5);
		int *C = new int[n+1];
		int *P = new int[n+1];
		
		for (int i = 1; i <= n; i++)
		{
			double A;
			cin >> C[i] >> A;
			P[i] = (int)(A * 100 + 0.5);
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = P[i]; j <= money; j++)
			{
				DP[j] = max(DP[j], DP[j - P[i]] + C[i]);
			}
		}

		cout << DP[money] << "\n";

		delete[] C;
		delete[] P;
	}

	return 0;
}