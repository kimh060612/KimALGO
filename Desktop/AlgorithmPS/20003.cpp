#include <iostream>

using namespace std;
typedef long long ll;

int n;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	ll l = -1, m = -1;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		int o = a > b ? gcd(a, b) : gcd(b, a);
		a /= o;
		b /= o;
		if (l == -1 || m == -1) {
			l = a;
			m = b;
		}
		else {
			l = l > a ? gcd(l, a) : gcd(a, l);
			int j = m > b ? gcd(m, b) : gcd(b, m);
			m = m * b / j;
		}
	}

	ll k = l > m ? gcd(l, m) : gcd(m, l);
	cout << l / k << " " << m / k << endl;
	return 0;
}