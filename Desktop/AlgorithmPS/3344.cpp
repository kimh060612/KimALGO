#include <iostream>

using namespace std;
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	bool isOdd = false;
	cin >> n;

	if (n % 2)	isOdd = true;

	if ((!isOdd && n % 6 != 2) || (isOdd && (n - 1) % 6 != 2))
	{
		if (isOdd)	n--;
		for (int i = 1; i <= n / 2; i++)
			cout << 2 * i << "\n";
		for (int i = 1; i <= n / 2; i++)
			cout << 2 * i - 1 << "\n";
		if (isOdd)	cout << n + 1 << "\n";
	}

	else if ((!isOdd && n / 6 != 0) || (isOdd && (n - 1) / 6 != 2))
	{
		if (isOdd)	n--;
		for (int i = 1; i <= n / 2; i++)
			cout << 1 + (2 * i + n / 2 - 3) % n << "\n";
		for (int i = n / 2; i > 0; i--)
			cout << n - (2 * i + n / 2 - 3) % n << "\n";
		if (isOdd)	cout << n + 1 << "\n";
	}

	return 0;
}