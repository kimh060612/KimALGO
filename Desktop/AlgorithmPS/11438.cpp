#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

int n, m;
vector<int> T[100001];
int depth[100001];
int Parent[100001][60];

void makeTree(int now) {
    for (int nx: T[now]) {
        if (depth[nx] == -1) {
            Parent[nx][0] = now;
            depth[nx] = depth[now] + 1;
            makeTree(nx);
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
        int a, b;
        cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
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
        cout << a << "\n";
    }
    return 0;
}