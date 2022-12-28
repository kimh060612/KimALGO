#include <iostream>

using namespace std;

int A[101], S[101];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        if (A[i - 1] == A[i] && A[i] == 1) S[i] = S[i - 1] + 1;
        else if (A[i] == 1) S[i] = 1;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += S[i];
    cout << sum << endl;
    return 0;
}