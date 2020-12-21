#include <iostream>

using namespace std;

long long DP[21][21][21];

long long Enjoyable_resrcusion(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)return 1;
	if (a > 20 || b > 20 || c > 20)return Enjoyable_resrcusion(20,20,20);

	long long &ret = DP[a][b][c];
	if (ret != 0)return ret;

	if (a < b && b < c) ret = Enjoyable_resrcusion(a, b, c - 1) + Enjoyable_resrcusion(a, b - 1, c - 1) - Enjoyable_resrcusion(a, b - 1, c);
	else ret = Enjoyable_resrcusion(a - 1, b, c) + Enjoyable_resrcusion(a - 1, b - 1, c) + Enjoyable_resrcusion(a - 1, b, c - 1) - Enjoyable_resrcusion(a - 1, b - 1, c - 1);

	return ret;
}

int main()
{
	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)break;
		cout << "w(" << a << ", " << b << ", " << c << ")" << " = " << Enjoyable_resrcusion(a, b, c) << endl;
	}
	
	return 0;
}