#include <iostream>

using namespace std;

int A[250001], DP[250001];

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0) break;
        for (int i = 1; i <= n; i++) cin >> A[i];
        for (int i = 1; i <= n; i++) DP[i] = max(A[i], DP[i - 1] + A[i]);
        int ans = -987654321;
        for (int i = 1; i <= n; i++) ans = max(ans, DP[i]);
        cout << ans << endl;
    }
    return 0;
}