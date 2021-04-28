#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int DP[101];
vector<pair<int ,int>> S;

int List2(int s)
{
    int &ret = DP[s];
    if (ret != -1) return ret;
    ret  = 1;
    for (int i = s + 1; i < N; i++)
    {
        if (S[s].second < S[i].second)ret = max(ret, List2(i) + 1);
    }
    return ret;
}

int main()
{
    cin >> N;    
    for (int i = 1; i <= N; i++)
    {
        DP[i - 1] = -1;
        int a, b;
        cin >> a >> b;
        S.push_back({a ,b});
    }

    sort(S.begin(), S.end());

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, List2(i));
    }

    cout << N - ans << endl;

    return 0;
}