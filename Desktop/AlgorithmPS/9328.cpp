#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;
using iip = pair<int, int>;

ifstream fin("input.txt");

int h, w;
int A[105][105], check[105][105], doc[105][105], keyCheck[105][105];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int K[30];

bool InRange(int y, int x) { return (1 <= y && y <= h) && (1 <= x && x <= w); }
bool canGetIn(int a) {
    if (a == 0 || (40 <= a && a <= 65) || a == 2) return true;
    if ((10 <= a && a <= 35) && K[a - 9]) return true;
    return false;
}
void refresh() {
    memset(check, 0, sizeof(check));
}

int BFS(int sy, int sx) {
    queue<iip> Q;
    Q.push({ sy, sx });
    int ans = 0;

    check[sy][sx] = 1;
    if (40 <= A[sy][sx] && A[sy][sx] <= 65 && !keyCheck[sy][sx]) {
        refresh();
        K[A[sy][sx] - 39] = 1;
        keyCheck[sy][sx] = 1;
    }
    else if (A[sy][sx] == 2 && !doc[sy][sx]) {
        doc[sy][sx] = 1;
        ans ++;
    }

    while (!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!InRange(ny, nx) || check[ny][nx] || A[ny][nx] == 1) continue;
            if (A[ny][nx] == 0) {
                Q.push({ ny, nx });
                check[ny][nx] = 1;
            }
            else if (10 <= A[ny][nx] && A[ny][nx] <= 35) {
                if (K[A[ny][nx] - 9]) {
                    Q.push({ ny, nx });
                    check[ny][nx] = 1;
                }
            }
            else if (40 <= A[ny][nx] && A[ny][nx] <= 65) {
                if (!keyCheck[ny][nx]) {
                    K[A[ny][nx] - 39] = 1;
                    refresh();
                    keyCheck[ny][nx] = 1;
                }
                Q.push({ ny, nx });
                check[ny][nx] = 1;
            }
            else if (A[ny][nx] == 2) {
                if (!doc[ny][nx]) {
                    ans ++;
                    doc[ny][nx] = 1;
                }
                Q.push({ ny, nx });
                check[ny][nx] = 1;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t --) {
        memset(K, 0, sizeof(K));
        memset(check, 0, sizeof(check));
        memset(doc, 0, sizeof(doc));
        memset(keyCheck, 0, sizeof(keyCheck));
        memset(A, 0, sizeof(A));
        std::cin >> h >> w;
        for (int i = 1; i <= h; i++) {
            string s;
            std::cin >> s;
            for (int j = 0; j < w; j++) {
                int k;
                if (s[j] == '.') k = 0;
                else if (s[j] == '$') k = 2;
                else if (s[j] == '*') k = 1;
                else if (65 <= s[j] && s[j] <= 65 + 25) k = 10 + s[j] - 65;
                else if (97 <= s[j] && s[j] <= 97 + 25) k = 40 + s[j] - 97;
                A[i][j + 1] = k;
            }
        }
        string key;
        std::cin >> key;
        if (key[0] != '0') {
            for (int i = 0; i < key.size(); i++) 
                K[key[i] - 96] = 1;
        }
        int ans = 0;
        for (int j = 1; ; j++)
        {
            refresh();
            int tmp = 0;
            for (int i = 1; i <= h; i++) 
                if (canGetIn(A[i][1]) && !check[i][1])
                    tmp += BFS(i, 1);
            for (int i = 1; i <= h; i++) 
                if (canGetIn(A[i][w]) && !check[i][w])
                    tmp += BFS(i, w);
            for (int i = 1; i <= w; i++) 
                if (canGetIn(A[1][i]) && !check[1][i])
                    tmp += BFS(1, i);
            for (int i = 1; i <= w; i++) 
                if (canGetIn(A[h][i]) && !check[h][i])
                    tmp += BFS(h, i);
            ans += tmp;
            if (tmp == 0) break;
        }
        
        std::cout << ans << "\n";
    }
    return 0;
}