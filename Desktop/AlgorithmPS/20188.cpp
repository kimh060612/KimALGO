#include <iostream>
#include <vector>
#define MAX 300005

using namespace std;
using ll = long long;

int check[MAX];
ll N, DP[MAX], ans;
vector<int> T[MAX], G[MAX];

void makeTree(int now) {
    check[now] = 1;
    for (auto nx: G[now]) {
        if (!check[nx]) {
            T[now].push_back(nx);
            makeTree(nx);
        }
    }
}

ll func(ll x) { return x * (x - 1) / 2; }
ll dfs(int now) {
    ll &ret = DP[now];

    ret = 1;
    for (auto nx: T[now]) {
        if (DP[nx] == 0) ret += dfs(nx);
    }
    ans += (func(N) - func(N - ret));
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    makeTree(1);

    dfs(1);
    cout << ans - func(N) << "\n";
    return 0;
}