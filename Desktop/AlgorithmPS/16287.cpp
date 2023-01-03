#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAXW 799994

using namespace std;
using iip = pair<int, int>;

int w, n, A[5001], DP[MAXW], check[MAXW];
vector<iip> Cache;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> n;
    for (int i = 1;i <= n; i++) {
        cin >> A[i];
        check[A[i]] += 1;
    }
    bool ans = false;
    sort(A + 1, A + 1 + n);

    for(int i = 1; i <= n; i++) 
    { // w == 10
        for (int j = i + 1; j <= n; j++) {
            DP[A[i] + A[j]] += 1;
        }
    }
    // for (int i = 1; i <= w; i++) {
    //     cout << "(" << i << "," << DP[i] << ")" << " ";
    // }
    // cout << endl;

    for(int i = 1; i <= n; i++) 
    { // w == 21
        for (int j = i + 1; j <= n; j++) {
            int now = A[i] + A[j]; // 6
            if (w - now >= 0 && DP[w - now]) {
                int pair_w = w - now; // 15
                int other_i = pair_w - A[i]; // 1(A[i]), 14(other_i)
                int other_j = pair_w - A[j]; // 5(A[j]), 10(other_j)
                if ((other_i > 0 && other_j > 0) && !check[other_i] && !check[other_j]) ans = true;
            }
        }
    }

    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}