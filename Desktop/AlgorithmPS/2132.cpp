#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N;
int F[10001], check[10001], node[10001];
vector<int> V[10001];

void search(int x)
{
	queue<int> Q;
	Q.push(x);

	while (!Q.empty())
	{
		int y = Q.front();
		Q.pop();

		for (int i = 0; i < V[y].size(); i++)
		{
			int ny = V[y][i];
			if (!check[ny])
			{
				check[ny] = 1;
				Q.push(ny);
				node[ny] = node[y] + F[ny];
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> F[i];
	}

	for (int i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	memset(check, 0, sizeof(check));
	memset(node, 0, sizeof(node));
	int max_fruit = F[1], max_index = 1;
	check[1] = 1; node[1] = F[1];
	search(1);
	for (int i = 2; i <= N; i++)
	{
		if (max_fruit < node[i])
		{
			max_fruit = node[i];
			max_index = i;
		}
	}

	memset(check, 0, sizeof(check));
	memset(node, 0, sizeof(node));
	check[max_index] = 1; node[max_index] = F[max_index];
	int ans = F[max_index], ans_index = max_index;
	search(max_index);
	for (int i = 1; i <= N; i++) 
	{
		if (ans < node[i])
		{
			ans = node[i];
			ans_index = i;
		}
	}

	int ans_min; 
	if (max_fruit == ans) ans_min = 1;
	else ans_min = (max_index < ans_index ? max_index : ans_index);
	cout << ans << " " << ans_min << endl;

	return 0;
}