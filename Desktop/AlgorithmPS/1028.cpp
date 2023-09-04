#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int R, C, Map[2000][2000];
ll cul[1000][1000], cdl[1000][1000], cur[1000][1000], cdr[1000][1000], ret;

ll min(ll a, ll b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        string c;
        cin >> c;
        for (int j = 1; j <= C; j++) {
            Map[i][j] = c[j - 1] - '0';
        }
    }

    for (int i = R; i >= 1; i--) {
        for (int j = 1; j <= C; j++) {
            if (Map[i][j] == 1) {
                cdl[i][j] = cdl[i + 1][j - 1] + 1;
                cdr[i][j] = cdr[i + 1][j + 1] + 1;
            }
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (Map[i][j] == 1) {
                cul[i][j] = cul[i - 1][j - 1] + 1;
                cur[i][j] = cur[i - 1][j + 1] + 1;
            }
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            int down = min(cdl[i][j], cdr[i][j]);
            for (int k = 1; k <= down; k++) {
                if(Map[i + 2*(k - 1)][j] && cul[i + 2*(k - 1)][j] >= k && cur[i + 2*(k - 1)][j] >= k) ret = max(ret, k);
            }
            int upper = min(cdr[i][j], cur[i][j]);
            for (int k = 1; k <= upper; k++) {
                if(Map[i][j + 2*(k - 1)] && cul[i][j + 2*(k - 1)] >= k && cdl[i][j + 2*(k - 1)] >= k) ret = max(ret, k);
            }
        }
    }

    cout << ret << "\n";
    return 0;
}