#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, X;
vector<pair<int, int>> Edge[1001];
int dist[1001], distX[1001];

void distance(int s, bool isX)
{
	int *dist_arr = isX ? distX : dist;
	priority_queue<pair<int, int>> Q;
	Q.push({ dist_arr[s], s });

	while (!Q.empty())
	{
		int cur = Q.top().second;
		int distance_ = Q.top().first * (-1);
		Q.pop();
		
		if (dist_arr[cur] < distance_) continue;
		for (int i = 0; i < Edge[cur].size(); i++)
		{
			int next = Edge[cur][i].first;
			int next_dist = Edge[cur][i].second + distance_;
			if (next_dist < dist_arr[next])
			{
				dist_arr[next] = next_dist;
				Q.push({ next_dist * (-1), next });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> X;
	for (int i = 1; i <= M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Edge[a].push_back({b, c});
	}

	for (int i = 1; i <= N; i++)
	{
		distX[i] = 987654321;
		dist[i] = 987654321;
	}
	distX[X] = 0;
	distance(X, true);

	int ans = -987654321;
	for (int i = 1; i <= N; i++)
	{
		if (i == X) continue;
		for (int i = 1; i <= N; i++) dist[i] = 987654321;
		dist[i] = 0;
		distance(i, false);
		int goback;
		goback = dist[X] + distX[i];
		ans = goback > ans ? goback : ans;
	}

	cout << ans << endl;
	return 0;
}