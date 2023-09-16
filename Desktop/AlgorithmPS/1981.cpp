#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#define INF 987654321

using namespace std;
using ll = long long;
using iip = pair<int, int>;
using iiip = pair<int, iip>;

int N, A[105][105], check[105][105], valMax = -INF, valMin = INF;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
bool InRange(int y, int x) { return (1 <= y && y <= N) && (1 <= x && x <= N); }

bool bfs(int ub, int lb) {
    if (!(lb <= A[1][1] && A[1][1] <= ub)) return false;
    memset(check, 0, sizeof(check));
    queue<iip> Q;
    Q.push({ 1, 1 });
    check[1][1] = 1;

    while (!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        if (y == N && x == N) return true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!(lb <= A[ny][nx] && A[ny][nx] <= ub)) continue;
            if (!check[ny][nx] && InRange(ny, nx)) {
                check[ny][nx] = 1;
                Q.push({ ny, nx });
            }
        }
    }
    return false;
}

ll biSearch() {
    int s = 0, e = valMax - valMin;
    int mid = (s + e) / 2;
    ll ret = INF;
    while (s <= e) {
        bool exists = false;
        for (int x = valMin; x <= valMax; x++) {
            exists = bfs(x + mid, x);
            if (exists) break;
        }
        if (exists) {
            ret = min(ret, mid);
            e = mid - 1;
        } else s = mid + 1;
        mid = (s + e) / 2;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int in = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            valMax = max(valMax, A[i][j]);
            valMin = min(valMin, A[i][j]);
        }
    }

    int ret = biSearch();
    cout << ret << "\n";
    return 0;
}