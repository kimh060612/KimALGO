#include <iostream>

using namespace std;

double A[5][5], s[5];

void prob_trans()
{
	double tmp[5];
	for (int i = 1; i <= 4; i++)
	{
		double res = 0.;
		for (int j = 1; j <= 4; j++)
		{
			res += A[i][j] * s[j];
		}
		tmp[i] = res;
	}
	for (int i = 1; i <= 4; i++) s[i] = tmp[i];
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout.precision(4);
	cout << fixed;
	for (int i = 1; i <= m; i++)
	{
		char a, b;
		double p;
		cin >> a >> b >> p;
		int k = a - 'A' + 1;
		int l = b - 'A' + 1;
		A[l][k] = p;
	}
	for (int i = 1; i <= 4; i++) s[i] = 0.25;

	for (int i = 1; i <= n; i++) prob_trans();
	for (int i = 1; i <= 4; i++) cout << s[i] * 100 << endl;

	return 0;
}