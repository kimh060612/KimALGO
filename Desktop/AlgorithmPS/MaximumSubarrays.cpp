#include <iostream>
#define MAX 5000
#define max(a, b) a > b ? a : b

using namespace std;

int A[MAX + 1];
int DP[MAX + 1];

int main()
{
    int n, c;
    cin >> c;
    for (int j = 0; j < c; j++)
    {
        int Max = -0x7fffffff;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        DP[0] = A[0];
        for (int i = 1; i < n; i++)
        {
            DP[i] = max(A[i], A[i] + DP[i-1]);
        }
        for (int i = 0; i < n; i++) Max = max(Max, DP[i]);
        cout << Max << endl;
    }

    return 0;
}

