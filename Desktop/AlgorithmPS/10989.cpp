#include <iostream>
#include <algorithm>

using namespace std;

int A[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        A[a] ++;
    }

    for (int i = 1; i < 10001; i++)
    {
        if (A[i] == 0) continue;
        for (int j = 0; j < A[i]; j++)cout << i << "\n";
    }
    return 0;   
}