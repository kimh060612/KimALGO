#include <iostream>

using namespace std;

int check[20001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i <= 10000; i++)
	{
		int k = i, d = 0;
		while (k > 0)
		{
			int a = k % 10;
			d += a;
			k /= 10;
		}
		d += i;
		check[d] = 1;
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (!check[i]) cout << i << endl;
	}
	return 0;
}