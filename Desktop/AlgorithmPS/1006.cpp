#include <iostream>
#include <fstream>
#include <string.h>
#define MAXN 10001
 
using namespace std;

int N, W, A[MAXN * 2], cBind[10][MAXN * 2];
int DP[10][MAXN * 2], check[MAXN * 2];

ofstream fout("output.txt");
ifstream fin("input.txt");

int min(int a, int b) { return a < b ? a : b; }
int positionInner(int a, int dir) {
    if (a == 0) return 1;
    if (dir == 1) return N + a;
    else if (dir == 2) return (a == N ? 1 : a + 1);
    else if (dir == 3)return a == 1 ? N : a - 1;
    else return a;
}

int positionOutter(int a, int dir) {
    if (dir == 1) return a - N;
    else if (dir == 2) return a == 2 * N ? (N == 1 ? 1 : N + 1) : a + 1;
    else if (dir == 3) return (a == (N + 1) ? (N == 1 ? 1 : 2 * N) : a - 1);
    else return a;
}

int search(int now, int dir, int depth) {
    if (depth == 2 * N) return 0;
    int &ret = DP[dir][now];
    if (ret != -1) return ret;
    // cout << now << " " << dir << " " << depth << endl << endl;
    if (dir == 0) { // 현재 now 단독으로 한 부대를 투입시켜야하는 경우
        check[now] = now;
        ret = 987654321;
        for (int j = 1; j <= 3; j++) {
            int next_idx = now > N ? positionOutter(now, j) : positionInner(now, j);
            if (!check[next_idx]) {
                ret = min(ret, 1 + search(next_idx, 0, depth + 1));
            }
        }
        check[now] = 0;
    }
    else { // now와 next가 묶여서 한 부대로 처리해야하는 경우
        int next_idx = now > N ? positionOutter(now, dir) : positionInner(now, dir);
        check[now] = next_idx;
        check[next_idx] = now;
        ret = 987654321;
        for (int j = 1; j <= 3; j++) {
            if (j == dir) continue;
            if (cBind[j][next_idx]) {
                int nn_idx = next_idx > N ? positionOutter(next_idx, j) : positionInner(next_idx, j);
                if (!check[nn_idx]) {
                    ret = min(ret, 1 + search(nn_idx, j, depth + 2));
                }
            } else {
                int nn_idx = next_idx > N ? positionOutter(next_idx, j) : positionInner(next_idx, j);
                if (!check[nn_idx]) {
                    ret = min(ret, 1 + search(nn_idx, 0, depth + 1));
                }
            }
        }
        check[now] = 0;
        check[next_idx] = 0;
    }
    
    // for (int i = 1; i <= 2 * N; i++) {
    //     cout << check[i] << " ";
    // }
    // cout << " "  << ret << endl << endl;
    return ret;
}

int main()
{
    int t;
    fin >> t;
    while (t--) {
        memset(DP, -1, sizeof(DP));
        memset(check, 0, sizeof(check));
        fin >> N >> W;
        for (int i = 1; i <= 2 * N; i++) {
            fin >> A[i];
        }
        for (int i = 0; i <= 3; i++)
            cBind[i][0] = 1;
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
        int ans = search(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}


// for (int i = 1; i <= 2 * N; i++)
// {
//     if (check[i]) continue;
//     for (int j = 1; j <= 3; j++) {
//         if (cBind[j][i]) {
//             int next_idx = i > N ? positionOutter(i, j) : positionInner(i, j);
//             if (!check[next_idx]) {
//                 check[next_idx] = i;
//                 check[i] = next_idx;
//                 ret = min(ret, search(i, dir, j, depth + 2) + 1); // 한번 묶어서 처리하는 iteration ==> 개수를 줄이게됨!
//                 check[next_idx] = 0;
//                 check[i] = 0;
//             }
//         }
//     }
//     check[i] = i;
//     ret = min(ret, search(i, dir, 0, depth + 1) + 1); // 갯수 줄이는 것에 기여하지 않는 iteration
//     check[i] = 0;
// }