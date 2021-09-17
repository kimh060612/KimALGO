#include <iostream>
#include <algorithm>

using namespace std;

int A[5];

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        cin >> A[i];
    }
    sort(A + 1, A + 1 + 4);
    int a, b;
    cin >> a >> b;
    int sum = max(a, b);
    for (int i = 1; i <= 3; i++)
    {
        sum += A[5 - i];
    }
    cout << sum << endl;
    return 0;
}