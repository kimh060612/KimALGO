#include <iostream>
#include <memory.h>

using namespace std;

int N; 
long long DP[65][10];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int A;
		cin >> A;
		memset(DP, 0, sizeof(DP));
		for (int i = 0; i <= 9; i++)
		{
			DP[1][i] = 1;
			DP[2][i] = 10 - i;
		}
		for (int i = 3; i <= A; i++)
		{
			long long sum = 0;
			for (int j = 0; j <= 9; j++)
			{
				sum += DP[i - 1][j];
			}
			DP[i][0] = sum;
			for (int j = 1; j <= 9; j++)
			{
				DP[i][j] = DP[i][j - 1] - DP[i - 1][j - 1];
			}
		}

		long long answer = 0;
		for (int j = 0; j <= 9; j++)answer += DP[A][j];
		cout << answer << endl;
	}

	return 0;
}