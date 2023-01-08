#include <iostream>
#include <fstream>
#include <string.h>
#define MAXN 10001
 
using namespace std;

int N, W, A[MAXN * 2], cBind[5][MAXN * 2], endpoint;
int DP[6][MAXN * 2], isCovered[MAXN * 2];

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

int position(int now, int dir) { return now > N ? positionOutter(now, dir) : positionInner(now, dir); }
int dirSwap(int dir) {
    if (dir == 2) return 3;
    else if (dir == 3) return 2;
    else if (dir == 1) return 1;
    else return 1;
}

int dirTable(int dir) {
    if (dir == 1) return 2;
    else if (dir == 2) return 1;
    else return 1;
}

int search(int now, int prev_dir, int mergedWithPrev) { 
    // now: 현재 적의 배치를 판단할 위치 
    //    -> depth의 역할도 해야함! 모두 다 돌았는지를 판단할 수 있는 기준 역할도 겸해야함!
    // prev_dir: 이전 위치에서 현재 위치로 온 방향
    if (now == endpoint && !isCovered[endpoint]) return 1;
    if (now == endpoint) return 0; 
    int pdir = prev_dir != 0 ? dirSwap(prev_dir) : 0;
    int &ret = DP[isCovered[now]][now];
    // if (ret != -1) return ret;
    int next_dir = dirTable(prev_dir);
    int next_pos = position(now, next_dir);
    ret = 987654321;
    // fout << now << " " << prev_pos << " " << isCovered[now] << endl << endl;
    for (int i = 1; i <= 2 * N; i++) 
        fout << isCovered[i] << " ";
    fout << endl << endl;
    if (isCovered[now] != 0) { // 현재 위치가 이미 묶여 있어서 다른 위치랑 묶을 수 없는 경우
        ret = min(ret, search(next_pos, next_dir, 0));
    } else { // 현재 위치를 다른 위치랑 묶을 수 있는 경우
        for (int j = 1; j <= 3; j++) {
            if (j == pdir) continue;
            if (cBind[j][now]) { // 일단 묶일 수 있는지 체크
                int merge_pos = position(now, j);
                if (!isCovered[merge_pos]) {
                    isCovered[now] = j;
                    isCovered[merge_pos] = dirSwap(j);
                    ret = min(ret, search(next_pos, next_dir, merge_pos == next_pos) + 1); // 묶어 놓고 시작한다.
                    isCovered[merge_pos] = 0;
                    isCovered[now] = 0;
                } 
            }
        }
        isCovered[now] = 4;
        ret = min(ret, search(next_pos, next_dir, 0) + 1); // 대충 안 묶고 다음 위치로 넘어감.
        isCovered[now] = 0;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);

    int t;
    fin >> t;
    while (t--) {
        memset(DP, -1, sizeof(DP));
        memset(isCovered, 0, sizeof(isCovered));
        memset(cBind, 0, sizeof(cBind));
        fin >> N >> W;
        endpoint = N % 2 == 0 ? N : 2 * N;
        for (int i = 1; i <= 2 * N; i++) {
            fin >> A[i];
        }
        for (int i = 1; i <= 2 * N; i++) {
            // 1개 소대로 2개 구역을 맡아야할때
            for (int j = 1; j <= 3; j++) {
                int next_idx = position(i, j);
                int next_w = A[i] + A[next_idx];
                if (next_w <= W) // i와 next_idx의 Node를 한개 소대로 처리 가능
                    cBind[j][i] = 1;
            }
        }
        int ans = search(1, 0, 0);
        std::cout << ans << endl;
    }
    return 0;
}