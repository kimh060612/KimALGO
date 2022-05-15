#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k = 0;
		cin >> n;
		while (n > 0)
		{
			int mod = n % 2;
			if (mod == 1) {
				cout << k << " ";
			}
			k++;
			n /= 2;
		}
		cout << endl;
	}
	return 0;
}