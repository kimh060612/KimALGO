#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, M, check[100005], rcheck[100005];
vector<int> G[100005], comp;

void dfs(int x) {
    check[x] = 1;

    for (auto nx: G[x]) {
        if (!check[nx]) dfs(nx);
    }
    comp.push_back(x);
}

void rdfs(int x) {
    check[x] = 1;

    for (auto nx: G[x]) {
        if (!check[nx]) rdfs(nx);
    }
}

int solution() {
    memset(check, 0, sizeof(check));
    comp.clear();
    
    int ret = 0;
    for (int i = 1; i <= N; i++) {
        if (!check[i]) {
            dfs(i);
        }
    }

    memset(check, 0, sizeof(check));
    for (int i = comp.size() - 1; i >= 0; i--) {
        int now = comp[i];
        if (!check[now]) {
            rdfs(now);
            ret ++;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t --) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) G[i].clear();
        for (int i = 1; i <= M; i++) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
        }
        cout << solution() << "\n";
    }
    return 0;
}