#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>

#define max(a,b)(a > b ? a : b)
#define swap(a,b){int t; t = a; a = b; b = t;} 
typedef long long int lli;

using namespace std;

int cost[10003];
vector <int> map[10003];

vector <int> tree[10003];
bool visit[10003];
queue <int> q;

void getTree(int start)
{
	q.push(start);

	while (!q.empty())
	{
		int here = q.front();
		visit[here] = true;
		q.pop();

		for (int i = 0; i < map[here].size(); i++)
		{
			if (!visit[map[here][i]])
			{
				tree[here].push_back(map[here][i]);
				q.push(map[here][i]);
			}
		}
	}
}

lli dy(int here, int i)
{
	lli ret = 0;

	for (int j = 0; j < tree[here].size(); j++)
	{
		int next = tree[here][j];
		if (i == 1) ret += dy(next, 0);
		else ret += max(dy(next, 0), cost[next] + dy(next, 1));
	}

	return ret;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> cost[i];


	for (int i = 1; i < n; i++)
	{
		int from, to;
		cin >> from >> to;

		map[from].push_back(to);
		map[to].push_back(from);
	}

	getTree(1);

	cout << max(dy(1, 0), cost[1] + dy(1, 1)) << endl;

	return 0;
}
