#include <iostream>
#include <vector>
#include <string.h>
#include <tuple>

using namespace std;
using iip = pair<int, int>;

int V, Q, K, check[1001];
vector<int> T[1001];
int Cost[1001][5]; // 1: R, 2: G, 3: B
int DP[1001][5][10001]; // i번째 Node가 j-color이고 여기까지의 비용합이 k일때 이를 루트로 하는 서브트리가 취할 수 있는 경우의 수 
// K로 나누어 떨어질 수 있어야함.
// G - G 연결은 불가.
// B는 G끼리만 연결 가능.

int dfs(int now, int ncolor, int nowCost, int parent) {
    if (T[now].size() == 0) return DP[now][ncolor][Cost[now][ncolor]] = Cost[now][ncolor];
    int &ret = DP[now][ncolor][nowCost];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < T[now].size(); i++) {
        int next = T[now][i];
        if (next == parent) continue;
        for (int j = 1; j <= 3; j++) {
            if (ncolor == 3 && j == 3) continue;
            if (ncolor == 2 && j != 3) continue;

        }
    }

}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> Q >> K;
    for (int i = 1; i < V; i++) {
        int a, b;
        cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    for (int i = 1; i <= V; i++)
        cin >> Cost[i][1] >> Cost[i][2] >> Cost[i][3];
    memset(DP, -1, sizeof(DP));

    int ans = 0;
    cout << ans << "\n";
    return 0;
}