#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define INF 9e18

using namespace std;
typedef long long ll;

ll M;
vector <pair<ll, ll>> V;

unsigned long long combination(unsigned long long n, unsigned long long k) {
	unsigned long long higher_idx;
	unsigned long long lower_idx;
	if(k > n-k) {
		higher_idx = k;
		lower_idx = n - k;
	} else {
		higher_idx = n - k;
		lower_idx = k;
	}
	double product = 1.0;
	double factor;
	unsigned long long idx;
	for(idx=n; idx>higher_idx; idx--) {
		factor = (double)idx / double(lower_idx - (n - idx));
		product *= factor;
	}
	return (unsigned long long)(product + 0.5);
}

ll search(ll k) {
	ll s = k, e = M;
	ll mid = (s + e) / 2;
	bool ans = false;
	while (s <= e) {
		mid = (s + e) / 2;
		ll nCr = combination(mid, k);
		if (nCr <= 0 || nCr > (ll)pow(10, 15)) nCr = INF;
		if (nCr == M) 
		{
			ans = true;
			break;
		}
		else if (nCr > M) e = mid - 1;
		else s = mid + 1;
	}
	if (ans)return mid;
	else return -1;
}

int main() {
	cin >> M;
	// r == 1
	if (M == 2) {
		V.push_back({ M, 1 });
	}
	else {
		V.push_back({ M, 1 });
		V.push_back({ M, M - 1 });
	}

	// else 
	for (ll i = 2; i <= 50; i++)
	{
		ll N = search(i);
		if (N == -1) continue;
		if (N == i * 2) V.push_back({ N, i });
		else {
			V.push_back({ N, i });
			V.push_back({ N, N - i });
		}
	}

	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	
	cout << V.size() << endl;
	for (long long i = 0; i < V.size(); i++)
	{
		cout << V[i].first << " " << V[i].second << "\n";
	}
	return 0;
}