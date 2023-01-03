#include <iostream>
#include <string.h>
#define MAXN 10001
 
using namespace std;

int N, W, A[MAXN * 2], cBind[10][MAXN * 2];
int DP[MAXN * 2], check[MAXN * 2];

int min(int a, int b) { return a < b ? a : b; }

int positionInner(int a, int dir) {
    if (dir == 1) return N + a;
    else if (dir == 2) return (a == N ? 1 : a + 1);
    else return a == 1 ? N : a - 1;
}

int positionOutter(int a, int dir) {
    if (dir == 1) return a - N;
    else if (dir == 2) return a == 2 * N ? (N == 1 ? 1 : N + 1) : a + 1;
    else return (a == (N + 1) ? (N == 1 ? 1 : 2 * N) : a - 1);
}

int search(int now) {
    if (now > 2 * N) return 2 * N;
    if (DP[now] != 0) return DP[now];

    int &ret = DP[now];
    ret = 2 * N;
    int next = now + 1;
    for (int i = 1; i <= 2 * N; i++)
    {
        if (i == now) continue;
        for (int j = 1; j <= 3; j++) {
            if (cBind[j][i]) {
                int next_idx = i > N ? positionOutter(i, j) : positionInner(i, j);
                if (!check[next_idx] && !check[i]) {
                    check[next_idx] = 1;
                    check[i] = 1;
                    ret = min(ret, search(i) - 1); // 한번 묶어서 처리하는 iteration ==> 개수를 줄이게됨!
                    check[next_idx] = 0;
                    check[i] = 0;
                }
            } 
        }
        if (!check[i]) {
            check[i] = 1;
            ret = min(ret, search(i)); // 갯수 줄이는 것에 기여하지 않는 iteration
            check[i] = 0;
        }
    }
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
        for (int i = 1; i <= 2 * N; i++) {
            // 1개 소대로 1개 구역을 맡아야할때
            cBind[0][i] = 1;
            // 1개 소대로 2개 구역을 맡아야할때
            for (int j = 1; j <= 3; j++) {
                int next_idx = i > N ? positionOutter(i, j) : positionInner(i, j);
                int next_w = A[i] + A[next_idx];
                if (next_w <= W) // i와 next_idx의 Node를 한개 소대로 처리 가능
                    cBind[j][i] = 1;
            }
        }
        int ans = search(0);
        cout << ans << endl;
    }
    return 0;
}

