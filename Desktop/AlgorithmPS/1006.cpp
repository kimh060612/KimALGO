#include <iostream>
#include <fstream>
#include <string.h>
#define MAXN 10001
 
using namespace std;

int N, W, A[MAXN * 2], cBind[10][MAXN * 2];
int DP[10][10][MAXN * 2], check[MAXN * 2];

ifstream fin("input.txt");

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

int search(int now, int prev_dir, int dir, int depth) {
    if (depth == 2 * N) return 2 * N;
    int &ret = DP[dir][prev_dir][now];
    if (ret != 987654321) return ret;

    for (int i = 1; i <= 2 * N; i++)
    {
        if (check[i]) continue;
        for (int j = 1; j <= 3; j++) {
            if (cBind[j][i]) {
                int next_idx = i > N ? positionOutter(i, j) : positionInner(i, j);
                if (!check[next_idx]) {
                    check[next_idx] = i;
                    check[i] = next_idx;
                    ret = min(ret, search(i, dir, j, depth + 2) - 1); // 한번 묶어서 처리하는 iteration ==> 개수를 줄이게됨!
                    check[next_idx] = 0;
                    check[i] = 0;
                }
            }
        }
        check[i] = i;
        ret = min(ret, search(i, dir, 0, depth + 1)); // 갯수 줄이는 것에 기여하지 않는 iteration
        check[i] = 0;
    }
    for (int i = 1; i <= 2 * N; i++)
        cout << check[i] << " ";
    cout << " " << ret << endl << endl;
    return ret;
}

int main()
{
    int t, c = 1;
    fin >> t;
    while (t--) {
        fin >> N >> W;
        for (int i = 0; i <= 2 * N; i++)
            for (int j = 0; j <= 3; j++)
                for (int k = 0; k <= 3; k++)
                    DP[j][k][i] = 987654321;
        for (int i = 1; i <= 2 * N; i++) {
            fin >> A[i];
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
        int ans = search(0, 0, 0, 0);
        cout << c << " " << ans << endl;
        c++;
    }
    return 0;
}

