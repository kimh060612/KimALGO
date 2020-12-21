#include <iostream>
#include <memory.h>

using namespace std;

int DP[10001];

int main()
{

	int T;
	cin >> T;
	for (int t = 1; t<= T; t++)
	{
		int N, M;
		cin >> N;
		int *A = new int[N + 1];
		memset(DP,0,sizeof(DP));
		for (int i = 1; i <= N; i++)
		{
			cin >> A[i];
		}
		cin >> M;
		DP[0] = 1;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (A[i] <= j)DP[j] += DP[j - A[i]];
			}
		}

		cout << DP[M] << endl;

		delete[] A;
	}

	return 0;
}