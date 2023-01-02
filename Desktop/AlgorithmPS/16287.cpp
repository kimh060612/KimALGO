#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAXW 799994

using namespace std;

int w, n, A[5001], DP[MAXW], check[MAXW];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> n;
    for (int i = 1;i <= n; i++) {
        cin >> A[i];
        check[A[i]] = 1;
    }
    bool ans = false;
    sort(A + 1, A + 1 + n);

    for(int i = 1; i <= n; i++) 
    {
        for (int j = i + 1; j <= n; j++) {
            DP[A[i] + A[j]] = 1;
            if (w - (A[i] + A[j]) >= 0 && DP[w - (A[i] + A[j])]) {
                int tmp = w - (A[i] + A[j]);
                if (tmp - A[i] < 0 || tmp - A[j] < 0) continue;
                int k = tmp - A[i];
                if (check[k] || check[A[i]]) DP[A[i] + A[j]] = 0;
            }
        }
    }

    for (int i = 10; i <= w; i++) 
    {
        if (DP[i] && DP[w - i]) ans = true;
    }

    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}