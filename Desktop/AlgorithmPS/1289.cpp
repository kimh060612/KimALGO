#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
using ll = long long;
using iip = pair<ll, ll>;

vector<iip> G[100001];
vector<iip> T[100001];
ll N, visited[100001];
ll ret;

void makeTree(ll now) {
    visited[now] = 1;
    for (auto elem: G[now]) {
        ll nx = elem.first;
        ll nw = elem.second;
        if (!visited[nx]) {
            T[now].push_back({ nx, nw });
            makeTree(nx);
        }
    }
}

ll dfs(const ll now) {
    ll mul = 1, temp;
    for (auto elem: T[now]) {
        int nx = elem.first;
        temp = dfs(nx) * elem.second % MOD;
        ret =  (ret + temp * mul) % MOD;
        mul = (temp + mul) % MOD;
    }
    return mul;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (ll i = 1; i < N; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({ b, w });
        G[b].push_back({ a, w });
    }
    makeTree(1);

    dfs(1);
    cout << ret << "\n";
    return 0;
}