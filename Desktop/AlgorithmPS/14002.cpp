#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A[1001], DP[2][1001];
int ans, ans_i;
vector<int> K;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++)
    {
        DP[0][i] = -1;
        DP[1][i] = 1;
        for (int j = 1; j <= i; j++)
        {
            if (A[i] > A[j] && DP[1][i] < DP[1][j] + 1)
            {
                DP[1][i] = DP[1][j] + 1;
                DP[0][i] = j;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (ans < DP[1][i])
        {
            ans = DP[1][i];
            ans_i = i;
        }
    }

    int t = ans_i;
    while (t != -1)
    {
        K.push_back(A[t]);
        t = DP[0][t];
    }

    reverse(K.begin(), K.end());
    cout << ans << endl;
    for (int i = 0; i < K.size(); i++)
    {
        cout << K[i] << " ";
    }
    cout << endl;
    return 0;
}