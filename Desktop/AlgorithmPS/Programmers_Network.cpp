#include <vector>
#include <queue>

using namespace std;

int visited[200], k = 1;

void BFS(int s, vector<vector<int>> &edges)
{
	if (visited[s] != 0) return;
	queue<int> Q;
	Q.push(s);

	k += 1;
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		visited[x] = k;
		for (int i = 0; i < edges[x].size(); i++)
		{
			if (edges[x][i] && visited[i] == 0 && x != i) {
				Q.push(i);
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		BFS(i, computers);
	}

	answer = k - 1;
	return answer;
}