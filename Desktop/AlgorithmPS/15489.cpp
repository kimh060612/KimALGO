#include <iostream>

using namespace std;
typedef long long ll;

ll nCr[31][31];

int main()
{
    int r, c, w;
    nCr[1][1] = 1;
    for (int i = 2; i <= 30; i++)
    {
        nCr[i][1] = 1;
        nCr[i][i] = 1;
        for (int j = 2; j < i; j++)
        {
            nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
        }
    }
    cin >> r >> c >> w;
    int k = 1;
    ll ans = 0;
    for (int i = r; i < r + w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            ans += nCr[i][c + j];
        }
        k ++;
    }
    cout << ans << endl;
    return 0;
}