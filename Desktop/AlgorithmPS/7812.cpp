#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
using ll = long long;
using iip = pair<ll, ll>;

ll N, check[10001];
vector<iip> T[10001];
iip DP[10001];
ll Memo[10001];
// DP[i].first: 1번 Node를 Root로 i번 Node의 Subtree에서 다른 노드로 가는 가중치의 총합 
// DP[i].second: 1번 Node를 Root로 i번 Node의 Subtree안의 노드의 갯수

ll min(ll a, ll b) { return a < b ? a : b; }

iip dfs(ll now, ll nowDist) {
    iip &ret = DP[now];
    if (ret.first != 0 && ret.second != 0) return ret;

    check[now] = 1;
    ret = { 0, 1 };
    for (auto nx: T[now]) {
        ll next = nx.first;
        ll nextDist = nowDist + nx.second;
        if (!check[next]) {
            iip nxres = dfs(next, nx.second);
            ret = { ret.first + nxres.first + nx.second * nxres.second, ret.second + nxres.second };
        }   
    }
    return ret;
}

void dfs2(ll now) {
    for (auto nx: T[now]) {
        ll next = nx.first;
        if (!check[next]) {
            Memo[next] = Memo[now] + nx.second * (N - 2 * DP[next].second);
            check[next] = 1;
            dfs2(next);
            check[next] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        cin >> N;
        if (N == 0) break;
        for (ll i = 1; i <= N; i++) T[i].clear();
        for (ll i = 1; i < N; i++) {
            ll a, b, w;
            cin >> a >> b >> w;
            T[a + 1].push_back({ b + 1, w });
            T[b + 1].push_back({ a + 1, w });
        }
        memset(DP, 0, sizeof(DP));
        memset(check, 0, sizeof(check));
        dfs(1, 0); // 1번을 기준 노드로 한 Tree 생성 
        Memo[1] = DP[1].first;
        memset(check, 0, sizeof(check));
        check[1] = 1;
        dfs2(1);
        ll ans = 1e18;
        for (int i = 1; i <= N; i++) ans = min(ans, Memo[i]);
        cout << ans << "\n";
    }
    return 0;
}