#include <iostream>

using namespace std;

int P[51][51];

int Pnk(int n, int k)
{
	if (k > n) return 0;
	int &ret = P[n][k];
	if (ret != 0) return ret;

	return ret = Pnk(n - 1, k) + Pnk(n - 1, k - 1);
}

int main()
{
	int n, m;
	cin >> n >> m;


	for (int i = 1; i <= 50; i++) P[i][0] = 1;
	for (int i = 1; i <= 50; i++) P[i][1] = i;
	for (int i = 1; i <= 50; i++) P[i][i] = 1;

	cout << Pnk(m - 1, m - n) << endl;

	return 0;
}