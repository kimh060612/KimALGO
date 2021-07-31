#include <iostream>

using namespace std;

int A[101];

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	int ans = -987654321;

	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			for (int k = j + 1; k <= N; k++)
			{
				int sum = A[i] + A[j] + A[k];
				if (sum <= M)
				{
					ans = max(sum, ans);
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}