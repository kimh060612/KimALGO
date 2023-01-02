#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ip = pair<int, int>;

unsigned long long DP[101][101];
int Broken[101][101][3];
int n, m, k;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

bool isBroken(int sx, int sy, int ex, int ey) {
    if (Broken[sx][sy][0] && ((sx + 1) == ex) && (sy == ey)) return true;
    else if (Broken[sx][sy][1] && (sx == ex) && ((sy + 1) == ey)) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((a == c && b == (d + 1)) || (b == d && a == (c + 1))) {
            swap(a, c);
            swap(b, d);
        }
        if (a == c && ((b + 1) == d)) Broken[a][b][1] = 1;
        else Broken[a][b][0] = 1;
    }

    DP[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        if (isBroken(i - 1, 0, i, 0)) break;
        DP[0][i] = DP[0][i - 1];
    }

    for (int i = 1; i <= m; i++) {
        if (isBroken(0, i - 1, 0, i)) break;
        DP[i][0] = 1;
    }   

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (!isBroken(j, i - 1, j, i)) DP[i][j] += DP[i - 1][j];
            if (!isBroken(j - 1, i, j, i)) DP[i][j] += DP[i][j - 1];
        }
    }

    cout << DP[m][n] << endl;
    return 0;
}