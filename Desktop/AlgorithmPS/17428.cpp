#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
using ll = long long;

ll N, K;
ll DP[51][51];

ll dfs(int a, int b) {
    if (b < 0) return 0;
    if (a == N) return b == 0 ? 1 : 0;
    ll &ret = DP[a][b];
    if(ret != -1) return ret;
    return ret = dfs(a + 1, b + 1) + dfs(a + 1, b - 1);
}

void answer(int a, int b, ll k) {
    if(a == N) return;
    ll ret = dfs(a + 1, b + 1);
    if(ret <= k){
        cout << ')';
        answer(a + 1, b - 1, k - ret);
    }
    else{
        cout << '(';
        answer(a + 1, b + 1, k);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    memset(DP, -1, sizeof(DP));
    if(dfs(0,0) <= K) cout << -1 << "\n";
    else {
        answer(0, 0, K);
        cout << "\n";
    }
    return 0;
}