#include <iostream>

using namespace std;

int N, M;
vector<int> T[100001];
int parent[100001][17], depth[100001];

int dfs(int x, int depth) {
    for (int nx: T[x]) {
        
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }

    while (M--) {
        int r, u, v;

    }

    return 0;
}