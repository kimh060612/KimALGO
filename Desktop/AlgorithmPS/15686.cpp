#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;
int n, m, k, h;
pair<int, int> C[20];
pair<int, int> H[200];
int visited[20];
int DP[(1 << 16)];
vector<int> K;

int min(int a, int b) { return a < b ? a : b; }

int distance(int bits) 
{
	int ans = 0;
	for (int i = 1; i <= h; i++) 
	{
		int tmp = 987654321;
		for (int j = 0; j < k; j++)
		{
			if (bits & (1 << j)) tmp = min(abs(H[i].first - C[j + 1].first) + abs(H[i].second - C[j + 1].second), tmp);
		}
		ans += tmp;
	}
	return ans;
}

int getAll(int depth, int bits) {
	if (depth > m) return 987654321;
	int &ret = DP[bits];

	if (ret != -1) return ret;
	ret = distance(bits);

	for (int i = 0; i < k; i++)
	{
		if (!(bits & (1 << i))) {
			ret = min(ret, getAll(depth + 1, bits + (1 << i)));
		}
	}

	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int a;
			cin >> a;
			if (a == 2) {
				k++;
				C[k] = make_pair(i, j);
			}
			else if (a == 1) {
				h++;
				H[h] = make_pair(i, j);
			}
		}
	}

	memset(DP, -1, sizeof(DP));
	int ans = 987654321;
	for (int b = 0; b < k; b++)
		ans = min(getAll(1, 1 << b), ans);

	cout << ans << endl;
	return 0;
}