#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, K, D;
		int A[1001] = { 0, };
		int Time[1001] = { 0, };
		vector<int> E[1001];
		queue<pair<int, int>> Q;
		int input_edge[1001] = {0, };
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
		{
			cin >> A[i];
		}
		for (int i = 1; i <= K; i++)
		{
			int x, y;
			cin >> x >> y;
			E[x].push_back(y);
			input_edge[y] ++;
		}
		cin >> D;

		for (int i = 1; i <= N; i++) 
		{
			if (input_edge[i] == 0) 
			{ 
				Q.push({ i, 0 }); 
				Time[i] = A[i];
			}
		}

		for (int i = 1; i <= N; i++)
		{
			int now = Q.front().first;
			int ti = Q.front().second;
			Q.pop();

			if (now == D) break;

			for (int j = 0; j < E[now].size(); j++)
			{
				int next = E[now][j];
				input_edge[next] --;
				if (input_edge[next] == 0)
				{
					Q.push({next, ti + 1});
				}
				Time[next] = max(Time[next], Time[now] + A[next]);
			}
		}
		cout << Time[D] << endl;
	}
	return 0;
}