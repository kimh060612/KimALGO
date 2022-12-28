#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) 
{
	return b ? gcd(b, a%b) : a;
}

ll exEuclid(ll a, ll b, ll &s, ll &t) {
	if (b == 0) 
	{ 
		s = 1; t = 0; 
		return a;
	} 
	ll gcd = exEuclid(b, a%b, s, t); 
	ll tmp = t; 
	t = s - (a / b)*t; 
	s = tmp; 
	if (s <= 0) { //s를 양수로 
		s += b; t -= a;
	} 
	return gcd;
}
int main() 
{
	ll N, A;
	cin >> N >> A;
	ll add_inverse = N - A;
	ll mul_inverse;
	if (gcd(N, A) != 1) mul_inverse = -1;
	else {
		ll t;
		exEuclid(A, N, mul_inverse, t);
	}
	cout << add_inverse << " " << mul_inverse << endl;
	return 0;
}