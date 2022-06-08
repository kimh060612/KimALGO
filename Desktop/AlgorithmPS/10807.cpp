#include <iostream>

using namespace std;

int A[101];

int main()
{
    int n, t;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    cin >> t;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (t == A[i]) ans ++;
    }
    cout << ans << endl;
    return 0;
}