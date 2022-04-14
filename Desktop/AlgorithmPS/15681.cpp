#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
vector<int> E[100001];
vector<int> child[100001];
int DP[100001], parent[100001];

void makeTree(int curNode, int p)
{
	for (int i = 0; i < E[curNode].size(); i++)
	{
		if (E[curNode][i] != p)
		{
			child[curNode].push_back(E[curNode][i]);
			parent[E[curNode][i]] = curNode;
			makeTree(E[curNode][i], curNode);
		}
	}
}

void countSubTreeNode(int curNode)
{
	DP[curNode] = 1;
	for (int i = 0; i < child[curNode].size(); i++)
	{
		int x = child[curNode][i];
		countSubTreeNode(x);
		DP[curNode] += DP[x];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> r >> q;

	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	makeTree(r, -1);
	countSubTreeNode(r);

	for (int i = 1; i <= q; i++)
	{
		int x;
		cin >> x;
		cout << DP[x] << "\n";
	}

	return 0;
}