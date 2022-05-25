#include<iostream>
using namespace std;

typedef long long ll;

int max(int a, int b) { return a > b ? a : b; }

int d[100001][2][2];
int a[100001];
int n;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	d[1][0][0] = a[1];
	d[2][1][0] = a[1] + a[2] / 2;
	d[2][0][0] = a[2];
	int ans = 0;
	ans = max(d[1][0][0], d[2][1][0]);
	ans = max(ans, d[2][0][0]);
	
	for (int i = 3; i <= n; i++) {
		d[i][0][0] = a[i] + max(max(d[i - 3][0][0], d[i - 3][0][1]), d[i - 3][1][0]);
		d[i][0][1] = a[i] + max(max(d[i - 2][0][0], d[i - 2][0][1]), d[i - 2][1][0]);
		d[i][1][0] = a[i] / 2 + max(d[i - 1][0][0], d[i - 1][0][1]);
		ans = max(max(d[i][0][0], d[i][0][1]), d[i][1][0]);
	}

	cout << ans << endl;
	return 0;
}