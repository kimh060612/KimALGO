#include<iostream>

using namespace std;
typedef long long ll;

ll A, B, C;

ll binpow(ll a, ll b) {
	ll res = 1;

	while (b > 0) {
		if (b & 1)
			res = (res * a) % C;

		a = (a * a) % C;
		b >>= 1;
	}

	return res;
}


int main()
{
	cin >> A >> B >> C;
	cout << binpow(A, B) << endl; 
	
	return 0;
}