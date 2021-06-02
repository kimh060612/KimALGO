#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, T;
int DP[101][10001];
vector<pair<int, int>> V;
 
int main()
{
    cin >> N >> T;
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            if (V[i - 1].first > j) DP[i][j] = DP[i - 1][j];
            else DP[i][j] = max(V[i - 1].second + DP[i - 1][j - V[i - 1].first], DP[i - 1][j]);
        }
    }
    cout << DP[N][T] << endl;
    return 0;
}