#include <iostream>
#define MAX 100001

using namespace std;

int max(int a, int b){ return a > b ? a : b;}

int N;
int DP[MAX], A[MAX];

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
        if (ans < DP[i]) ans = DP[i];
    }

    cout << ans;

    return 0;
}