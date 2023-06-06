#include <iostream>

using namespace std;
using ll = long long;

int N, sz;
ll A[100005], B[100005], DP[100005];
ll dDP[100005], dB[100005];

double cross(int x, int y) {
    return (double) (dDP[y] - dDP[x]) / (double) (dB[x] - dB[y]);
}

void insert(ll b, ll dp) {
    dB[sz] = b;
    dDP[sz] = dp;
    while (sz > 1 && cross(sz - 2, sz - 1) > cross(sz - 1, sz)) {
        dB[sz - 1] = dB[sz];
        dDP[sz - 1] = dDP[sz];
        sz --;
    }
    sz++;
}

ll query(ll x) {
    int l = 0, r = sz - 1;
    while (l != r) {
        int mid = (l + r) / 2;
        if (cross(mid, mid + 1) <= x) l = mid + 1;
        else r = mid;
    }   
    return dDP[l] + dB[l] * x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];

    insert(B[1], 0);
    for (int i = 2; i <= N; i++) {
        DP[i] = query(A[i]);
        insert(B[i], DP[i]);
    }
    cout << DP[N] << "\n";
    return 0;
}