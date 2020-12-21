#include <iostream>

using namespace std;

int DP[31], N;

int main()
{
	cin >> N;
	DP[0] = 1;
	DP[2] = 3;
	if (N % 2 != 0)
	{
		cout << 0 << endl;
	}
	else
	{
		for (int i = 4; i <= N; i++)
		{
			for (int j = 2; j <= i; j += 2)
			{
				int tmp = j == 2 ? 3 : 2;
				DP[i] += tmp * DP[i - j];
			}
		}
		cout << DP[N] << endl;
	}
	return 0;
}