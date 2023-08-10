#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#define INF 1e18

using namespace std;
using ll = long long;
using iip = pair<ll, ll>;

struct Number {
    ll pri, data;
    Number(ll _pri, ll _data): pri(_pri), data(_data) {}
    bool operator<(const Number s) const {
        if (this->pri == s.pri) return this->data > s.data;
        return this->pri > s.pri;
    }
};
ll L, S[55], N, C[55], tN, full;
iip R[55];

ll sSeq(ll n) {
    if (n <= 2) return 0;
    return (n - 2) * (n - 1) / 2;
}

ll weight(ll i, ll l) {
    return (i * (2 * l - i - 1) / 2) - sSeq(i);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> L;
    for (int i = 1; i <= L; i++) {
        cin >> S[i];
    }
    cin >> N;
    tN = N;
    sort(S + 1, S + 1 + L);
    S[0] = 1;
    priority_queue<Number> pq;
    for (int i = 1; i <= L; i++) {
        pq.push(Number(0, S[i]));
        R[i - 1] = { S[i] - S[i - 1] - 1 , i - 1 };
        C[i - 1] = 1;
    }
    R[0].first++;
    R[L] = { INF, L };
    sort(R, R + 1 + L);
    ll last = S[L] + 1;
    while (tN--) {
        for (int i = 0; i < L; i++) {
            int w = R[i].first, k = R[i].second;
            int index = C[k];
            if (w % 2 == 1 && C[k] * 2 - 1 == w) {
                pq.push({ weight(index, w), S[k + 1] - C[k] });
            } else {
                if (w < 2 * C[k]) continue;
                if (k == 0) pq.push({ weight(index, w), C[k] });
                else pq.push({ weight(index, w), S[k] + C[k] });
                pq.push({ weight(index, w), S[k + 1] - C[k] });
            }
            C[k] ++;
        }
    }

    while (!pq.empty() && N > 0) {
        ll ret = pq.top().data;
        pq.pop();
        cout << ret << " ";
        N -= 1;
    }
    while (N > 0) {
        cout << last << " ";
        last++;
        N --;
    }
    cout << "\n";
    return 0;
}