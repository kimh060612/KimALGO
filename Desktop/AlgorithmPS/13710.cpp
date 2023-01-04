#include <iostream>

using namespace std;
typedef long long ll;

int N; 
ll A[100001], XOR[100001];

int step(ll k) { return k > 0 ? 1 : 0; }

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) XOR[i] = A[i] ^ XOR[i - 1];

    ll ans = 0;
    int bits[31] = {0, };
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j <= N; j++) {
            if (XOR[j] & (1 << i)) bits[i]++;
        }
    }

    for (int i = 0; i < 30; i++) ans += ((ll)1 << i) * bits[i] * (N + 1 - bits[i]);
    cout << ans << endl;
    return 0;
}