#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<int> E[510];
int count_[510];
int time[510];
int AT[510];

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> time[i];
		while (1)
		{
			int a;
			cin >> a;
			if (a == -1) break;
			E[a].push_back(i);
			count_[i] ++;
		}
	}

	queue<pair<int, int>> Q;
	for (int i = 1; i <= n; i++)
	{
		if (count_[i] == 0) {
			Q.push({ i, time[i] }); 
			AT[i] = time[i];
		}
	}

	while (!Q.empty())
	{
		int x = Q.front().first;
		int t = Q.front().second;
		Q.pop();

		for (int i = 0; i < E[x].size(); i++)
		{
			count_[E[x][i]]--;

			AT[E[x][i]] = max(t + time[E[x][i]], AT[E[x][i]]);
			if (count_[E[x][i]] == 0) Q.push({ E[x][i], AT[E[x][i]] }); 
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << AT[i] << "\n";
	}

	return 0;
}