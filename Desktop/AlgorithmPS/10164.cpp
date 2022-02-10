#include <iostream>

using namespace std;

int nCr[50][50];

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i <= 40; i++) nCr[0][i] = 1;
	for (int i = 1; i <= 40; i++)
	{
		nCr[i][i] = 1;
		nCr[i][0] = 1;
	}

	for (int i = 2; i <= 40; i++)
	{
		for (int j = 1; j < i; j++)
		{
			nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
		}
	}

	if (k != 0) {
		int w = (k % m == 0) ? m : k % m;
		int h = (k % m == 0) ? k / m : k / m + 1;

		int dw1 = w - 1;
		int dh1 = h - 1;

		int dw2 = m - w;
		int dh2 = n - h;

		cout << (long long)(nCr[dw1 + dh1][dw1] * nCr[dw2 + dh2][dw2]) << endl;
	}
	else {
		cout << (long long)(nCr[n + m - 2][n - 1]) << endl;
	}

	return 0;
}