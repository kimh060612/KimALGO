#include <iostream>

using namespace std;
typedef long long ll;

ll pizza(ll n)
{
	if (n == 1) return 0;
	if (n % 2 == 0) return (n / 2) * (n / 2) + 2 * pizza((n / 2));
	else return (n / 2) * (n / 2 + 1) + pizza(n / 2) + pizza(n / 2 + 1);
}

int main()
{
	int n;
	cin >> n;
	cout << pizza(n) << endl;
	return 0;
}