#include <iostream>
#define INF 1000001
#define min(a,b) a > b ? b : a

using namespace std;

int DP[5001];

int main()
{
    int n;
    int bonggi[2] = {3,5};
    cin >> n;
    for (int i = 1; i <= n; i++)DP[i] = INF;
    DP[0] = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <= n ;j++)
        {
            if(j >= bonggi[i])DP[j] = min(DP[j],DP[j-bonggi[i]]+1);
        }
    }

    if (DP[n] == INF)cout << -1 << endl;
	else cout << DP[n] << endl;

    return 0;
}