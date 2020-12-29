#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define min(a,b) a < b ? a : b 
#define MAX 1001
#define INF 987654321

using namespace std;

int N, M;
int A[MAX][MAX];
int DP[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

bool OutofRange(int y, int x) {return (x < 1 || x > M || y < 1 || y > N); }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> A[i][j];
            DP[i][j] = INF;
        }
    }
    if(A[1][1] == -1 or A[N][M] == -1){
        cout << -1 << "\n";
        return 0;
    }

    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int,pair<int,int> >>> pq;
    pq.push({A[1][1],{1,1}});
    while(!pq.empty()){
        int now_Y = pq.top().second.first;
        int now_X = pq.top().second.second;
        int now_num = pq.top().first;
        pq.pop();
        if(DP[now_Y][now_X] <= now_num){
            continue;
        }
        DP[now_Y][now_X] = now_num;
        if(now_Y == N and now_X == M){
            break;
        }
        for(int i = 0; i < 4; i++){
            int next_Y = now_Y + dy[i];
            int next_X = now_X + dx[i];
            int next_num = now_num + A[next_Y][next_X];
            if(next_num < DP[next_Y][next_X] && !OutofRange(next_Y, next_X) && A[next_Y][next_X] != -1){
                pq.push({next_num, {next_Y, next_X}});
            }
        }
    }

    if (DP[N][M] != INF)cout << DP[N][M] << endl;
    else cout << -1 << endl;

    return 0;
}