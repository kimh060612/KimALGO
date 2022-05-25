#include <iostream>

using namespace std;
typedef long long ll;

int N; 
ll A[100001], DP[100001], Sum[100001];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    
    DP[1] = A[1];
    Sum[1] = A[1];
    for (int i = 2; i <= N; i++)
    {
        ll ans = 0;
        DP[i] = A[i];
        for (int j = i - 1; j >= 1; j--)
        {
            DP[j] = DP[j] ^ A[i];
            ans += DP[j];
        }
        ans += A[i];
        Sum[i] = ans;
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) ans += Sum[i];

    cout << ans << endl;

    return 0;
}
