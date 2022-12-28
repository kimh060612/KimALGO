#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		n = (n + 1) / 2;
		cout << n * n << "\n";
	}
	return 0;
}