#include <iostream>
#include <tuple>
#define MAX 40000000
#define TWFACT 479001600


using namespace std;
using ll = long long;

ll N, K, P;
ll facto[MAX + 1];
ll map[20];

ll fpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % P;
        }
        a = (a * a) % P;
        b /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K >> P;
    if (N >= P) {
        cout << 0 << "\n";
        return 0;
    }
    else if (N == 2) {
        cout << 2 % P << "\n";
        return 0;
    }
    else if (N == 3) {
        if (K == 3) {
            ll ans = 1;
            for (int i = 1; i <= 720; i++) {
                ans = (ans * i) % P;
            }
            cout << ans << "\n";
            return 0;
        } else if (K == 2) {
            cout << 720 % P << "\n";
            return 0;
        } else {
            cout << 0 << "\n";
            return 0;
        }
        return 0;
    }
    else if (N >= 13) {
        cout << 0 << "\n"; // 여기서부터 최대 N은 12, 최소 3
        return 0;
    }
    else if (K >= 3) {
        cout << 0 << "\n"; // 여기서부터 K는 2
        return 0;
    }
    else if (N == 12) {
        if (P > TWFACT) {
            ll ans = 1;
            for (ll k = TWFACT + 1; k <= P - 2; k++)
                ans = (ans * k) % P;
            ans = fpow(ans, P - 2);
            cout << ans << "\n";
            return 0;
        } else {
            cout << 0 << "\n";
            return 0;
        }
    }

    facto[0] = 1;
    facto[1] = 1;
    facto[2] = 2 % P;
    facto[3] = 6 % P;
    for (int i = 4; i <= MAX; i++) {
        facto[i] = (facto[i - 1] * i) % P;
    } // 나올 수 있는 최대 수: (12!)!
    map[0] = 1;
    map[1] = 1;
    map[2] = 2 % P;
    map[3] = 6 % P;
    for (int i = 4; i <= 11; i++) {
        map[i] = map[i - 1] * i;
    } // 나올 수 있는 최대 수: (12!)!

    cout << facto[map[N]] << "\n";
    return 0;
}