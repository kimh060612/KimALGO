#include <iostream>

using namespace std;

long long A[101], B[101];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> B[i];

    A[1] = B[1];
    for (int i = 2; i <= n; i++)
    {
        long long sum = 0;
        for (int j = 1; j < i ;j++) sum += A[j];
        A[i] = i * B[i] - sum;
    }

    for (int i = 1; i <= n; i++) cout << A[i] << endl;
    return 0;
}