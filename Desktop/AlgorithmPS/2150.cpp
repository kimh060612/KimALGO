#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <algorithm>

using namespace std;
using vec = vector<int>;

int V, E, check[10005];
int num = 0;
vector<int> G[10005], rG[10005], tmp;
vector<vector<int>> ret;
stack<int> S;

bool compare(const vec &i, const vec &j) {
    return i[0] < j[0];
}

void dfs(int x) {
    check[x] = 1;
    for (auto nx: G[x]) {
        if (!check[nx]) dfs(nx);
    }
    S.push(x);
}

void dfsReverse(int x) {
    check[x] = 1;
    ret[num].push_back(x);
    for (auto nx: rG[x]) {
        if (!check[nx]) dfsReverse(nx);
    }
}

void SCC() {
    memset(check, 0, sizeof(check));
    for (int i = 1; i <= V; i++) {
        if (!check[i]) dfs(i);
    }

    memset(check, 0, sizeof(check));
    ret.resize(10005);
    while (!S.empty()) {
        int now = S.top();
        S.pop();
        if (!check[now]) {
            tmp.clear();
            num ++;
            dfsReverse(now);
        }
    }
    for (int i = 1; i <= num; i++) sort(ret[i].begin(), ret[i].end());
    sort(ret.begin() + 1, ret.begin() + 1 + num, compare);

    cout << num << "\n";
    for (int i = 1; i <= num; i++) {
        for (auto node: ret[i]) {
            cout << node << " ";
        }
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;
    for (int i = 1; i <= E; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        rG[b].push_back(a);
    }

    SCC();
    return 0;
}