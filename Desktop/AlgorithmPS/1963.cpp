#include <iostream>
#include <queue>
#include <string.h>
#include <string>

using namespace std;

int visited[10001];
bool isPrime[10001];

void Eratos()
{
	for (int i = 2; i <= 10000; i++)
		isPrime[i] = true;

	for (int i = 2; i <= 10000; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= 10000; j += i)
				isPrime[j] = false;
		}
	}
}

bool inRange(int x) { return (1000 <= x && x <= 9999); }

int BFS(int s, int e)
{
	queue<pair<string, int>> Q;
	Q.push({ to_string(s) , 0 });
	visited[s] = 1;
	int ans = -1;

	while (!Q.empty())
	{
		string x = Q.front().first;
		int num = Q.front().second;
		Q.pop();

		if (stoi(x) == e)
		{
			ans = num;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				string tmp = x;
				tmp[i] = j + '0';
				int nx = stoi(tmp);
				if (inRange(nx) && isPrime[nx] && !visited[nx])
				{
					visited[nx] = 1;
					Q.push({ to_string(nx), num + 1 });
				}
			}
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	Eratos();
	while (t--)
	{
		int s, e;
		cin >> s >> e;
		memset(visited, 0, sizeof(visited));
		int ans = BFS(s, e);
		if (ans == -1) cout << "Impossible" << endl;
		else cout << ans << endl;
	}
	return 0;
}