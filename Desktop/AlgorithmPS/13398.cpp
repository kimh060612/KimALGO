#include <iostream>
#define MAX 100001

using namespace std;

int max(int a, int b){ return a > b ? a : b;}

int N;
int DP[MAX], A[MAX], DP2[MAX];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    int ans = -987654321;
    for (int i = 1; i <= N; i++)
    {
        DP[i] = max(A[i] + DP[i - 1], A[i]);        
    }

    for (int i = N; i >= 1; i--)
    {
        DP2[i] = A[i];
        if (i == N)continue;
        DP2[i] = max(DP2[i + 1] + A[i], DP2[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, DP2[i]);
    }


    for (int i = 1; i <= N; i++)
    {
        if (N == 1)continue;
        ans = max(ans, DP[i - 1] + DP2[i + 1]);
    }

    cout << ans << endl;

    return 0;
}