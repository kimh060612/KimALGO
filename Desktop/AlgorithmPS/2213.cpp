#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
using ll = long long;

int N, W[10001];
vector<int> ans;
vector<int> G[10001], T[10001];
int check[10001];
ll DP[4][10001];

ll max(ll a, ll b) { return a > b ? a : b; }

void makeTree(int now) {
    check[now] = 1;
    for (auto nx: G[now]) {
        if (!check[nx]) {
            T[now].push_back(nx);
            makeTree(nx);
        }
    }
}

ll dfs(int now, int con) {
    if (T[now].empty()) return con == 0 ? 0 : W[now];
    ll &ret = DP[con][now];
    if (ret != -1) return ret;

    ret = con == 0 ? 0 : W[now];
    for (auto nx: T[now]) {
        ll nxgo = dfs(nx, 1);
        ll nxno = dfs(nx, 0);
        if (con == 0) ret += max(nxgo, nxno);
        else ret += nxno; 
    }
    return ret;
}

void trace(int now, int con) {
    if (con) ans.push_back(now);
    for (auto nx: T[now]) {
        ll nxgo = DP[1][nx];
        ll nxno = DP[0][nx];
        if (con == 0) {
            if (nxgo < nxno) trace(nx, 0);
            else trace(nx, 1);
        } else {
            trace(nx, 0);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
    }
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    makeTree(1);
    memset(DP, -1, sizeof(DP));
    for (int i = 1; i <= N; i++) {
        if (T[i].empty()) {
            DP[0][i] = 0;
            DP[1][i] = W[i];
        }
    }

    ll ogo = dfs(1, 1);
    ll ono = dfs(1, 0);
    ll ret = max(ogo, ono);
    if (ogo < ono) trace(1, 0);
    else trace(1, 1);
    sort(ans.begin(), ans.end());

    cout << ret << "\n";
    for (auto node: ans) {
        cout << node << " ";
    }
    cout << "\n";
    return 0;
}