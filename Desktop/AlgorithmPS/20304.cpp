#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;
using iip = pair<int, int>;

int N, M, P[100005], safety[3000005];

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    queue<int> Q;
    for (int i = 0; i <= N; i++) safety[i] = 30;
    for (int i = 1; i <= M; i++) {
        cin >> P[i];
        safety[P[i]] = 0;
        Q.push(P[i]);
    }
    int ret = -INF;

    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();

        for (int i = 0; i <= 20; i++) {
            int nx = (1 << i) ^ x;
            if (nx <= N && safety[x] + 1 < safety[nx]) {
                safety[nx] = safety[x] + 1;
                ret = max(ret, safety[nx]);
                Q.push(nx);
            }
        }
    }

    cout << ret << "\n";

    return 0;
}