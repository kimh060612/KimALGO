#include <iostream>
#include <cmath>

using namespace std;

int DP[50001];

int main()
{
    ios::sync_with_stdio(0); 
	cin.tie(0); 
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        DP[i] = 1 + DP[i - 1];
        for (int j = 2; j * j <= i; j++)
        {
            DP[i] = min(DP[i], DP[i - j * j ] + 1);
        }
    }

    cout << DP[N] << endl;

    return 0;
}