#include <iostream>
using namespace std;

typedef long long ll;

int n, m;
int height[335][335];
char arr[335][335];
int ans;
struct stack {
	int first;
	int second;
};
stack st[335];

void func() {
	for (int j = 0; j < m; j++) {
		if (arr[0][j] == '0') height[0][j] = 1;
	}
	for (int j = 0; j < m; j++) {
		for (int i = 1; i < n; i++) {
			if (arr[i][j] == '0') height[i][j] = height[i - 1][j] + 1;
		}
	}
}
void func2(int startline) {
	int pos = n;
	int top = -1;
	for (int i = 0; i < m; i++) {
		int a = height[startline][i];
		if (top == -1) {
			top++;
			st[top].first = i;
			st[top].second = a;
		}
		else {
			if (st[top].second > a) {
				while (top >= 0 && st[top].second > a) {
					pos = st[top].first;
					int t = (i - st[top].first)*st[top].second;
					ans = ans < t ? t : ans;
					top--;
				}
				++top;
				st[top].first = pos;
				st[top].second = a;
			}
			else if (st[top].second == a) continue;
			else {
				top++;
				st[top].first = i;
				st[top].second = a;
			}
		}
	}
	for (int i = 0; i <= top; i++) {
		int t = (m - st[i].first)*st[i].second;
		ans = ans < t ? t : ans;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	func();
	for (int i = 0; i < n; i++) func2(i);
	cout << ans << '\n';
	return 0;
}