#include <iostream>
#include <vector>
#include <queue>
#define MAX 20010
#define INF 987654321

using namespace std;

int V, E;
int S;
vector<int> PATH;
vector<pair<int, int>> MAP[MAX];

int main()
{

	cin >> V >> E;
	cin >> S;

	for (int i = 1; i <= E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		MAP[a].push_back(make_pair(b,c));
	}

	PATH.assign(V+1, INF);
	PATH[S] = 0;
	priority_queue<pair<int, int>> Q;

	Q.push(make_pair(PATH[S],S));

	while (!Q.empty())
	{
		int cost = (-1)*Q.top().first;
		int node = Q.top().second;
		Q.pop();

		if (PATH[node] < cost)continue;

		for (int i = 0; i < MAP[node].size(); i++)
		{
			int next_PATH = cost + MAP[node][i].second;
			
			if (PATH[MAP[node][i].first] > next_PATH)
			{
				PATH[MAP[node][i].first] = next_PATH;
				Q.push(make_pair((-1)*next_PATH, MAP[node][i].first));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (PATH[i] != INF) cout << PATH[i] << "\n";
		else cout << "INF" << "\n";
	}

	return 0;
}