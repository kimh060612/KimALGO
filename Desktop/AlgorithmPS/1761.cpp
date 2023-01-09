#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;
using iip = pair<int ,int>;

int n, m;
vector<iip> T[40001];
int depth[40001];
long long dist[40001];
int Parent[40001][30];

void makeTree(int now) {
    for (iip nx: T[now]) {
        if (depth[nx.first] == -1) {
            Parent[nx.first][0] = now;
            depth[nx.first] = depth[now] + 1;
            dist[nx.first] = nx.second + dist[now];
            makeTree(nx.first);
        }
    }
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int h = (int)ceil(log2(n) + 1);
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        T[a].push_back({ b, c });
        T[b].push_back({ a, c });
    }
    memset(depth, -1, sizeof(depth));
    memset(Parent, -1, sizeof(Parent));
    depth[1] = 0;
    makeTree(1);

    for (int j = 0; j < h; j++) 
        for (int i = 2; i <= n; i++)
            if (Parent[i][j] != -1)
                Parent[i][j + 1] = Parent[Parent[i][j]][j];

    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        int u = a, v = b;
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int j = 0; diff; j++) {
            if (diff % 2) a = Parent[a][j];
            diff /= 2;
        }
        if (a != b) {
            for (int j = h - 1; j >= 0; j--) {
                if(Parent[a][j] != -1 && Parent[a][j] != Parent[b][j]){
                    a = Parent[a][j];
                    b = Parent[b][j];
                }
            }
            a = Parent[a][0];
        }
        cout << dist[u] + dist[v] - 2 * dist[a] << "\n";
    }
    return 0;
}