#include <iostream>

using namespace std;

int N;
int T[1500001], P[1500001];
int DP[1500001];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = max(DP[i - 1], ans);
        if (i + T[i] - 1 <= N) {
            DP[i + T[i] - 1] = max(ans + P[i], DP[i + T[i] - 1]);
        }
    }
    int MAX = 0;
    for (int i = 1; i <= N; i++) MAX = max(DP[i], ans);
    cout << MAX << endl;
    return 0;
}