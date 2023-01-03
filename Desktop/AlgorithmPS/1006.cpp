#include <iostream>
#include <string.h>
#define MAXN 10001
 
using namespace std;

int N, W, A[MAXN * 2], cBind[10][MAXN * 2];
int DP[MAXN * 2], check[MAXN * 2];

int min(int a, int b) { return a < b ? a : b; }
int position(int a, int mod, int dir) {
    if (dir == 1) return mod == N ? (mod + a) : (a - (mod / 2));
    if (dir == 2) return (a + 1) % mod;
    if (dir == 3) return (a - 1 + mod) % mod == 0 ? mod : (a - 1 + mod) % mod;
    else return a;
}

int search(int now, int depth) {
    if (depth == 2 * N) return 2 * N;
    if (DP[now] != 0) return DP[now];

    check[now] = 1;
    int &ret = DP[now];
    ret = 2 * N;
    for (int i = 1; i <= 3; i++) {
        if (cBind[i][now]) {
            int next_idx = now > N ? position(now, 2 * N, i) : position(now, N, i);
            if (!check[next_idx]) {
                check[next_idx] = 1;
                ret = min(ret, search(now + 1, depth + 1) - 1); // 한번 묶어서 처리하는 iteration ==> 개수를 줄이게됨!
                check[next_idx] = 0;
            }
        } 
    }
    cout << now << " " << depth << " " << ret << endl;
    ret = min(ret, search(now + 1, depth + 1)); // 갯수 줄이는 것에 기여하지 않는 iteration
    check[now] = 0;
    return ret;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> W;
        for (int i = 1; i <= 2 * N; i++) {
            cin >> A[i];
        }
        cBind[0][1] = 1;
        for (int j = 1; j <= 3; j++) {
            int next_idx = position(1, N, j);
            int next_w = A[1] + A[next_idx];
            if (next_w <= W) {
                cBind[j][1] = 1;
            } else {
                cBind[j][1] = 0;
            }
        }
        for (int i = 2; i <= 2 * N; i++) {
            // 1개 소대로 1개 구역을 맡아야할때
            cBind[0][i] = 1;
            // 1개 소대로 2개 구역을 맡아야할때
            for (int j = 1; j <= 3; j++) {
                int next_idx = i > N ? position(i, 2 * N, j) : position(i, N, j);
                int next_w = A[i] + A[next_idx];
                if (next_w <= W) // i와 next_idx의 Node를 한개 소대로 처리 가능
                    cBind[j][i] = 1;
            }
        }
        int ans = search(1, 0);
        cout << ans << endl;
    }
    return 0;
}