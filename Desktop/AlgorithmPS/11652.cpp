#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;

unordered_map<ll, int> map;
ll n, A[100001];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
		map[A[i]] += 1;
	}

	ll ans, ans_count = -1;
	for (auto it = map.begin(); it != map.end(); it++)
	{
		if (ans_count < it->second)
		{
			ans_count = it->second;
			ans = it->first;
		}
		else if (ans_count == it->second && ans > it->first)
			ans = it->first;
	}

	cout << ans << endl;

	return 0;
}