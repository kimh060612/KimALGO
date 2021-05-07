#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int A[1001];
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    sort(A + 1, A+ N + 1);
    for (int i = 1; i <= N; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}