#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
 
using namespace std;

struct info {
	int node;
	int fee;
	int dist;
};

// 우선순위큐 실행을 위한 커스텀 comparator
class compare {
public:
	bool operator()(info& e1, info& e2) {
		// compare d
		return e1.fee > e2.fee;
	}
};

//앞에는 다음 공항, 뒤는 cost
const int INF = 1000000007;
vector<info> idx[101];
int timeDelay[101][10001];
priority_queue<info, vector<info>, compare> pq;

int min(int a, int b) { return a < b ? a : b; }
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //T=테스트 케이스 수, N=공항의 수, M=지원 비용, K=티켓정보의 수
    int T, N, M, K;
    //u=출발공항, v=도착공항, c=비용, d=소요시간
    int u, v, c, d;
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        for (int i = 1; i <= N; i++) idx[i].clear();
        for (int i = 0; i < K; i++) {
            cin >> u >> v >> c >> d;
            idx[u].push_back({ v, c, d });
        }

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++)
                timeDelay[i][j] = INF;
        }
        timeDelay[1][0] = 0;
        pq.push({ 1, 0, 0 });
        while (!pq.empty()) {
            int cost = pq.top().fee;
            int time = pq.top().dist;
            int here = pq.top().node;
            pq.pop();
            if (timeDelay[here][cost] < time) continue;
            for (int i = 0; i < idx[here].size(); i++) {
                int nextCost = cost + idx[here][i].fee;
                int there = idx[here][i].node;
                int nextTime = time + idx[here][i].dist;
                if (nextCost > M) continue;
                if (timeDelay[there][nextCost] <= nextTime) continue;

                for (int j = nextCost; j <= M; j++) {
                    if (timeDelay[there][j] > nextTime) timeDelay[there][j] = nextTime;
                }
                pq.push({ there, nextCost, nextTime });
            }
        }
        int ret = INF;
        for (int i = 1; i <= M; i++)
            ret = min(ret, timeDelay[N][i]);
        if (ret == INF)
            printf("Poor KCM\n");
        else
            printf("%d\n", ret);
    }
    return 0;
}
