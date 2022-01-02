#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> V;
int DP[50];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        V.push_back({a, {b, c}});
    }

    sort(V.begin(), V.end());
    DP[1] = V[0].second.second;
        
    for (int i = 2; i <= n; i++)
    {
        int max_num = -987654321;
        int now_start = V[i - 1].first;
        DP[i] = V[i - 1].second.second;
        for (int j = 1; j <= i; j++)
        {
            if (now_start >= V[j - 1].second.first) {
                max_num = max(max_num, DP[j]);
            }
        }
        DP[i] = max(DP[i], V[i - 1].second.second + max_num);
    }
    int ans = -987654321;
    for (int i = 1; i <= n; i++) ans = max(ans, DP[i]);
    cout << ans << endl;
    return 0;
}