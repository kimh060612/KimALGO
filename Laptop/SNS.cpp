#include <iostream>
#include <fstream>
#include <vector>
#include <memory.h>
#define MAX 1000001
#define min(a,b) b > a ? a : b

using namespace std;

ifstream fin;
ofstream fout;

int N, DP[MAX][4];
vector<int> List[MAX], child[MAX];
vector<int> visited;

void DFS(int now)
{

	visited[now] = 1;

	for (int next: List[now])
	{
		if (!visited[next])
		{
			child[now].push_back(next);
			DFS(next);
		}
	}
}

int SNS(int now, int EA)
{
	int &ret = DP[now][EA];
	if (ret != -1)return ret;

	int Npick = MAX, pick = 1;
	for (int next : child[now])
	{
		pick += SNS(next, 1);
	}
	if (EA)
	{
		Npick = 0;
		for (int next: child[now])
		{
			Npick += SNS(next, 0);
		}
	}
	return ret = min(Npick, pick);
}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> N;
	visited.assign(N + 1, 0);
	for (int i = 1; i <= N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		List[a].push_back(b);
		List[b].push_back(a);
	}

	DFS(1);
	memset(DP, -1 ,sizeof(DP));
	cout << SNS(1,1) << endl;

	fin.close();
	fout.close();
	return 0;
}