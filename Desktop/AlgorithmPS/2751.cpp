#include <iostream>
#include <algorithm>

using namespace std;

int A[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    sort(A + 1, A + 1 + N);
    for (int i = 1; i <= N; i++)
    {
        cout << A[i] << "\n";
    }
    return 0;
}