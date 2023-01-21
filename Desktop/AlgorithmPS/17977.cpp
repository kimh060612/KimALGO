#include <iostream>

using namespace std;

int N, DP[1000001];

int main()
{
    cin >> N;
    DP[4] = 1;
    DP[5] = 2;
    for (int i = 6; i <= N; i++) {
        DP[i] = DP[i - (i / 2)] + 2;
    }
    cout << DP[N] << endl;
    return 0;
}