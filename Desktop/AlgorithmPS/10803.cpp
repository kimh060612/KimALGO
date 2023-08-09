#include <iostream>
#include <string.h>
#define INF 987654321

using namespace std;

int N, M;
int DP[10010][1010];

int min(int a, int b) { return a < b ? a : b; }
int dfs(int x, int y){
    if(x <= 0 || y <=0) return INF;
    if(x < y) return dfs(y, x);
    if (DP[x][y]) return DP[x][y];
    if(x % y == 0) return x / y;
    
    int &ret = DP[x][y] = DP[y][x];
    ret = INF;
    if(x >= 3 * y) ret = min(ret, dfs(x - y, y) + 1);
    else{
        for(int i = 1; i <= x / 2; i++)ret = min(ret, dfs(x - i, y) + dfs(i, y));
        for(int i = 1; i <= y / 2; i++)ret = min(ret, dfs(x, y - i) + dfs(x, i));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int ret = dfs(N, M);
    cout << ret << "\n";
    return 0;
}