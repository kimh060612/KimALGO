#include <iostream>

using namespace std;

int DP[11];

int main()
{
    int H, Y;
    cin >> H >> Y;
    DP[0] = H;
    for (int i = 1; i <= Y; i++)
    {
        int t = (int)DP[i - 1] * 1.05;
        if (i >= 3) t = max(t, (int)(DP[i - 3] * 1.2));
        if (i >= 5) t = max(t, (int)(DP[i - 5] * 1.35));
        DP[i] = t;
    }
    cout << DP[Y] << endl;
    return 0;
}