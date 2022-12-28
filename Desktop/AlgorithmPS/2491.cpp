#include <iostream>
#include <string.h>

using namespace std;

int A[100001], DP[100001];


int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> A[i];
        DP[i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        if (A[i] >= A[i - 1]) DP[i] = max(DP[i], DP[i - 1] + 1);
    }
    
    int ans = -1;
    for (int i = 1; i <= n; i++) ans = max(ans, DP[i]);

    for (int i = 1; i <= n; i++) DP[i] = 1;


    for (int i = 2; i <= n; i++)
    {
        if (A[i] <= A[i - 1]) DP[i] = max(DP[i], DP[i - 1] + 1);
    }

    for (int i = 1; i <= n; i++) ans = max(ans, DP[i]);

    cout << ans << endl;

    return 0;
}