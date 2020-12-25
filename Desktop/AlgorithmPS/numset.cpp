#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

int max(int a, int b) {return a > b ? a : b;}

int A[MAX + 1], DP[MAX + 1], N;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    sort(A + 1, A + 1 + N);

    DP[0] = 0;
    DP[1] = A[1];

    for (int i = 2; i <= N; i++)
    {
        DP[i] = max (DP[i - 1] + A[i], DP[i - 2] + A[i]*A[i-1]);
    }

    cout << DP[N] << endl;

    return 0;
}
