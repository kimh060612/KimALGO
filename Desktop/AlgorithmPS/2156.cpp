#include <iostream>

using namespace std;

int DP[10003], A[10003];

int get_max(int a, int b) { return a > b ? a : b; }
int main()
{
    int N;
    cin >> N;
    for (int i = 3; i < N + 3; i++)
    {
        cin >> A[i];
    }
    int ans = 0;
    for (int i = 3; i < N + 3; i++) {
        DP[i] = get_max(DP[i-3] + A[i-1] + A[i], DP[i-2] + A[i]);
        DP[i] = get_max(DP[i-1], DP[i]);
        ans = get_max(ans, DP[i]);
    }
    cout << ans << endl;
    return 0;
}