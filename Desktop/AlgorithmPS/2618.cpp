#include <iostream>
#include <string.h>
#include <vector>
#define INF 987654321

using namespace std;
using iip = pair<int, int>;
using ppp = pair<iip, iip>;

int N, W, nDP[1010][1010], rDP[1010];
iip A[1001];

int min(int a, int b) { return a < b ? a : b; }
int Abs(int x) { return x > 0 ? x : -x; }
int distance(iip a, iip b) { return Abs(a.first - b.first) + Abs(a.second - b.second); }
iip atA(int index, int flag) {
    if (flag == 1 && index == 0) return { 1, 1 };
    if (flag == 2 && index == 0) return { N, N };
    return A[index];
}

int dfs(int fp, int sp) {
    if (fp == W || sp == W) return 0;
    int &ret = nDP[fp][sp];
    if (ret != -1) return ret;

    int next = (fp > sp ? fp : sp) + 1;
    int dst1 = dfs(next, sp) + distance(A[next], atA(fp ,1));
    int dst2 = dfs(fp, next) + distance(A[next], atA(sp, 2));
    return ret = min(dst1, dst2);
}

void track(int fp, int sp) {
    if (fp == W || sp == W) return;
    int next = (fp > sp ? fp : sp) + 1;
    int dst1 = dfs(next, sp) + distance(A[next], atA(fp ,1));
    int dst2 = dfs(fp, next) + distance(A[next], atA(sp, 2));
    if (dst1 < dst2) {
        rDP[next] = 1;
        track(next, sp);
    } else {
        rDP[next] = 2;
        track(fp, next);
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> W;
    for (int i = 1; i <= W; i++) {
        cin >> A[i].first >> A[i].second;
    }
    memset(nDP, -1, sizeof(nDP));
    int ret = dfs(0, 0);
    track(0, 0);
    cout << ret << "\n";
    for (int i = 1; i <= W; i++) {
        cout << rDP[i] << "\n";
    }
    return 0;
}