#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll N, A[3005], DP[3005], wt, wh;
ll Sum[3005];

ll Abs(ll x) { return x < 0 ? -x : x; }
ll min(ll a, ll b) { return a < b ? a : b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    cin >> wt >> wh;
    sort(A + 1, A + 1 + N);
    for (int i = 1; i <= N; i++) Sum[i] = Sum[i - 1] + A[i];

    for (int i = 1; i <= N; i++) {
        DP[i] = DP[i - 1] + A[i] * wt;
        for (int j = i; j >= 1; j--) {
            int mid = (i + j) / 2;
            ll left = (A[mid] * (mid - j + 1) - (Sum[mid] - Sum[j - 1])) * wt;
			ll right = ((Sum[i] - Sum[mid - 1]) - (A[mid] * (i - mid + 1))) * wt;
            ll cost = left + right + wh;
            DP[i] = min(DP[i], DP[j - 1] + cost);
        }
    }

    cout << DP[N] << "\n";
    return 0;
}