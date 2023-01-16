#include <iostream>
#include <string>
#include <string.h>

using namespace std;
using ll = long long;

int N, A[20][20];
int DP[65537][20][20];

int max(int a, int b) { return a > b ? a : b; }
int dfs(ll now, int nowArtist, int cost, int depth) {
    int &ret = DP[now][nowArtist][cost];
    if (ret != -1) return ret;

    ret = depth;
    for (int i = 1; i <= N; i++) {
        if (nowArtist == i) continue;
        if (!(now & (1 << (i - 1))) && cost <= A[nowArtist][i]) {
            ret = max(ret, dfs(now | (1 << (i - 1)), i, A[nowArtist][i], depth + 1));
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            A[i][j + 1] = s[j] - '0';
        }
    }
    memset(DP, -1, sizeof(DP));
    int ans = dfs(1, 1, 0, 1);
    cout << ans << endl;
    return 0;
}
