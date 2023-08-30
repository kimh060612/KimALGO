#include <iostream>
#include <queue>
#define MAX 100005
#define INF 1e18

using namespace std;
using ll = long long;
using lip = pair<ll, int>;

ll N, D, K[MAX], DP[MAX];

ll max(ll a, ll b) { return a > b ? a : b; }
ll relu(ll x) { return x < 0 ? 0 : x; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> D;
    for (int i = 1; i <= N; i++) cin >> K[i];
    for (int i = 1; i <= N; i++) DP[i] = -INF;

    deque<ll> dq;
    ll ret = -INF;
    for (int i = 1; i <= N; i++) {
        while(!dq.empty()){
            if(dq.front() < i - D) dq.pop_front();
            else break;
        }

        if (dq.empty()) {
            DP[i] = K[i];
        } else {
            DP[i] = relu(DP[dq.front()]) + K[i];
        }
        ret = max(DP[i], ret);
        
        while(!dq.empty()){
            if(DP[dq.back()] <= DP[i]) dq.pop_back();
            else break;
        }
        dq.push_back(i);
    }
    cout << ret << "\n";
    return 0;
}