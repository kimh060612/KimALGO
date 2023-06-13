#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define INF 1e18

using namespace std;
using ll = long long;
using llp = pair<ll, ll>;

int N, H;
ll T[662144];
vector<llp> X;

ll min(ll a, ll b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }

void dfs(int now, int depth) {
    int left = 2 * now, right = 2 * now + 1;
    if (left <= N) dfs(left, depth + 1);
    X.push_back({ T[now], depth });
    if (right <= N) dfs(right, depth + 1);
}

int main()
{
    cin >> N;
    H = (int)ceil(log2(N + 1));
    for (int i = 1; i <= N; i++) {
        cin >> T[i];
    }
    X.push_back({ 0, 0 });
    dfs(1, 1);
    
    ll ret = -INF;
    for(int i = 1; i <= H; i ++){
        for(int j = i; j <= H; j++){
            ll now = 0;
            for(int k = 1; k <= N; k++){
                if(X[k].second < i || X[k].second > j) continue;
                now = now + X[k].first;
                ret = max(ret, now);
                if(now < 0) now=0;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}