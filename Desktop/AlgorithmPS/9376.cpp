#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <string.h>

using namespace std;
using ll = long long;
using iip = pair<int, int>;

int H, W, Map[105][105];
ll Mem[5][105][105];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
iip prison[3];

bool InRange(int y, int x) { return (0 <= y && y <= H + 1) && (0 <= x && x <= W + 1); }
int min(int a, int b) { return a < b ? a : b; }

void bfs(int type, int sy, int sx) {
    deque<iip> Q;
    Q.push_front({ sy, sx });
    Mem[type][sy][sx] = 0;

    while(!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop_front();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!InRange(ny, nx)) continue;
            if (Map[ny][nx] == 2 || Mem[type][ny][nx] != -1) continue;
            if (Map[ny][nx] == 3) {
                Q.push_back({ ny, nx });
                Mem[type][ny][nx] = Mem[type][y][x] + 1;
            } else {
                Q.push_front({ ny, nx });
                Mem[type][ny][nx] = Mem[type][y][x];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int cnt = 1;
        cin >> H >> W;
        for (int i = 1; i <= H; i++) {
            string s;
            cin >> s;
            for (int j = 1; j <= W; j++) {
                char t = s[j - 1];
                if (t == '.') Map[i][j] = 1;
                if (t == '*') Map[i][j] = 2;
                if (t == '#') Map[i][j] = 3;
                if (t == '$') {
                    Map[i][j] = 4;
                    prison[cnt].first = i;
                    prison[cnt].second = j;
                    cnt++;
                }
            }
            Map[i][0] = 1;
            Map[i][W + 1] = 1;
        }

        for (int j = 0; j <= W + 1; j++) {
            Map[0][j] = 1;
            Map[H + 1][j] = 1;
        }

        memset(Mem, -1, sizeof(Mem));
        bfs(0, 0, 0);
        bfs(1, prison[1].first, prison[1].second);
        bfs(2, prison[2].first, prison[2].second);
        
        ll ret = 987654321;
        ll tmp = 0;
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if (Map[i][j] == 2) continue;
                if (Mem[0][i][j] < 0 || Mem[1][i][j] < 0 || Mem[2][i][j] < 0) continue;
                tmp = (Mem[0][i][j] + Mem[1][i][j] + Mem[2][i][j]);
                if (Map[i][j] == 3) tmp = tmp - 2;
                ret = min(ret, tmp);
            }
        }
        cout << ret << "\n";
    }
    return 0;
}