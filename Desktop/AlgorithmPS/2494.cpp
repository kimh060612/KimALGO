#include <iostream>
#include <string>
#define INF 987654321

using namespace std;

int N, A[10001], E[10001], nDP[10001][10], rDP[10001][10];
int Mem[10001], tot, flag = 0;
string S, T;

int min(int a, int b) { return a < b ? a : b; }
int ABS(int x) { return x < 0 ? -x : x; }

int rightRotate(int x, int t) {
    return t > x ? -(10 - t + x) : t - x;
}

int leftRotate(int x, int t) {
    return t > x ? t - x : 10 - x + t;
}

int dfs(int depth, int bias) {
    if (depth == N + 1) return 0;
    int now = (A[depth] + bias + 10) % 10;
    int &ret = nDP[depth][now];
    if (ret != INF) return ret;
    int left = leftRotate(now, E[depth]), right = rightRotate(now, E[depth]);
    
    int leftCost = dfs(depth + 1, (bias + left) % 10) + left;
    int rightCost = dfs(depth + 1, bias) - right;

    ret = min(ret, min(leftCost, rightCost));
    rDP[depth][now] = leftCost < rightCost ? left : right;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S >> T;
    for (int i = 0; i < N; i++) {
        A[i + 1] = S[i] - '0';
        E[i + 1] = T[i] - '0';
        for (int k = 0; k < 10; k++) {
            nDP[i + 1][k] = INF;
        }
    }

    tot = dfs(1, 0);
    cout << tot << "\n";
    int idx = 1, num = A[1], bias = 0;
    while (1) {
        cout << idx << " " << rDP[idx][num] << "\n";
        if (rDP[idx][num] > 0) {
			bias += rDP[idx][num];
			bias %= 10;
		}
        idx++;
        if (idx == N + 1)
			break;
        num = (A[idx] + bias) % 10;
    }
    return 0;
}