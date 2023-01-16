#include <iostream>
#include <string.h>
#include <string>

using namespace std;
using ll = long long;

int N, P, A[20][20];
ll DP[65537][17];

ll min(ll a, ll b) { return a < b ? a : b; }
int dfs(ll now, int onFactory, int depth) {
    if (depth == P) return 0;
    ll &ret = DP[now][onFactory];
    if (ret != -1) return ret;

    ret = 987654321;
    for (int i = 1; i <= N; i++) {
        if ((now & (1 << (i - 1)))) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                if (!(now & (1 << (j - 1)))) {
                    ret = min(ret, dfs((now | (1 << (j - 1))), i, depth + 1) + A[i][j]);
                }
            }
        }
    }
    return ret;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
    string s;
    cin >> s;
    cin >> P;
    ll now = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'Y') {
            now |= (1 << i);
            P--;
        }
    memset(DP, -1, sizeof(DP));
    if (P <= 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = dfs(now, 0, 0);

    if (ans == 987654321 || ans == -1) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}