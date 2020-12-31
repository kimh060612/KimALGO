#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

int A[MAX + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 2*n; i++)
    {
        cin >> A[i];
    }

    sort(A + 1, A + 2*n + 1);

    int answer = 0x7fffffff;
    for (int i = 1; i <= n; i++)
    {
        answer = answer < A[i] + A[2*n - i + 1] ? answer : A[i] + A[2*n - i + 1];
    }

    cout << answer << endl;

    return 0;
}