#include <iostream>
#include <fstream>
#include <string.h>
#define MAXN 10001
 
using namespace std;

int N, W, A[MAXN * 2], cBind[5][MAXN * 2]; //, isEven; //, endpoint;
int DP[7][7][MAXN * 2], isCovered[MAXN * 2];

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

bool canProceedLast(int first, bool isUp) {
    if (first == 1) return isUp;
    if (first == 2) return !isUp;
    if (first == 3) return 0;
    else return 1;
}

int search(int now, int merge_dir, int first) { // 현재 위치에서 N번째 위치까지 몇개의 군집이 모이는가 (현재 위치의 이전에 merge된 것들이 있다면 제외)
    // now: 현재 적의 배치를 판단할 위치 
    //    -> depth의 역할도 해야함! 모두 다 돌았는지를 판단할 수 있는 기준 역할도 겸해야함!
    // merge_dir: 이전 node가 어느 방향과 병합되었는지.
    int above_pos = position(now, 1);
    int next_pos = position(now, 2);
    if (now == N) {
        if (first == 1 || first == 2) {
            if (merge_dir == 1) return 2;
            if (merge_dir == 2 || merge_dir == 3) return 1;
        }
        if (first == 3) return 2;
        if (first == 4) {
            if (merge_dir == 1 && cBind[1][now]) return 1;
            else if (merge_dir == 1) return 2;
            if (merge_dir == 2 || merge_dir == 3) return 1;
            if (merge_dir == 4) return 0;
        }
    }
    int &ret = DP[merge_dir][first][now];
    if (ret != -1) return ret;
    ret = 987654321;
    
    // 이전 노드와 결합하지 않음
    if (merge_dir == 1) {
        if (cBind[1][now]) ret = min(ret, search(next_pos, 1, first) + 1);
        bool canproceed = now != N - 1 ? true : canProceedLast(first, false);
        if (cBind[2][now] && canproceed) ret = min(ret, search(next_pos, 2, first) + (now == 1 && first != 4 ? 1 : 2));
        canproceed = now != N - 1 ? true : canProceedLast(first, true);
        if (cBind[2][above_pos] && canproceed) ret = min(ret, search(next_pos, 3, first) + (now == 1 && first != 4 ? 1 : 2));
        canproceed = now != N - 1 ? true : (first == 4);
        if (cBind[2][now] && cBind[2][above_pos] && canproceed) ret = min(ret, search(next_pos, 4, first) + 2);
        ret = min(ret, search(next_pos, 1, first) + 2);
    }
    // 이전의 아래쪽 노드와 결합함
    if (merge_dir == 2) {
        bool canproceed = now != N - 1 ? true : canProceedLast(first, true);
        if (cBind[2][above_pos] && canproceed) ret = min(ret, search(next_pos, 3, first) + 1);
        ret = min(ret, search(next_pos, 1, first) + 1);
    }
    // 이전의 위쪽 노드와 결합함
    if (merge_dir == 3) {
        bool canproceed = now != N - 1 ? true : canProceedLast(first, false);
        if (cBind[2][now] && canproceed) ret = min(ret, search(next_pos, 2, first) + 1);
        ret = min(ret, search(next_pos, 1, first) + 1);
    }
    // 이전의 위/아래 모든 노드와 결합함
    if (merge_dir == 4) {
        ret = min(ret, search(next_pos, 1, first));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        memset(DP, -1, sizeof(DP));
        memset(isCovered, 0, sizeof(isCovered));
        memset(cBind, 0, sizeof(cBind));
        cin >> N >> W;
        for (int i = 1; i <= 2 * N; i++) {
            cin >> A[i];
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

        if (N == 1) {
            if (cBind[1][1]) cout << 1 << endl;
            else cout << 2 << endl;
            continue;
        }

        int ans = 987654321;
        // 마지막과 아래 Node 묶기
        if (cBind[2][N]) ans = min(ans, search(1, 2, 1));
        // std::cout << ans << endl;
        // 마지막과 위쪽 Node 묶기
        if (cBind[2][2 * N]) ans = min(ans, search(1, 3, 2));
        // std::cout << ans << endl;
        // 마지막과 위 아래 둘다 묶기
        if (cBind[2][N] && cBind[2][2 * N]) ans = min(ans, search(1, 4, 3));
        // std::cout << ans << endl;
        // 마지막과 묶지 않는다.
        ans = min(ans, search(1, 1, 4));

        std::cout << ans << "\n";
    }
    return 0;
}


// for (int i = 1; i <= 2 * N; i++) 
//     fout << isCovered[i] << " ";
// fout << endl << endl;
// if (isCovered[now] != 0) { // 현재 위치가 이미 묶여 있어서 다른 위치랑 묶을 수 없는 경우
//     ret = min(ret, search(next_pos, next_dir, 0));
// } else { // 현재 위치를 다른 위치랑 묶을 수 있는 경우
//     for (int j = 1; j <= 3; j++) {
//         if (j == pdir) continue;
//         if (cBind[j][now]) { // 일단 묶일 수 있는지 체크
//             int merge_pos = position(now, j);
//             if (!isCovered[merge_pos]) {
//                 isCovered[now] = j;
//                 isCovered[merge_pos] = dirSwap(j);
//                 ret = min(ret, search(next_pos, next_dir, merge_pos == next_pos) + 1); // 묶어 놓고 시작한다.
//                 isCovered[merge_pos] = 0;
//                 isCovered[now] = 0;
//             } 
//         }
//     }
//     isCovered[now] = 4;
//     ret = min(ret, search(next_pos, next_dir, 0) + 1); // 대충 안 묶고 다음 위치로 넘어감.
//     isCovered[now] = 0;
// }