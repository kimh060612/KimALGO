#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#define MAXW 799994

using namespace std;

int w, n, A[5001], DP[MAXW];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> n;
    for (int i = 1;i <= n; i++) {
        cin >> A[i];
    }
    bool ans = false;

    for(int i = 1; i <= n; i++) 
    {
        for (int j = i + 1; j <= n; j++) {
            
            DP[A[i] + A[j]] = 1;
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