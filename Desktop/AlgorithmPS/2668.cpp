#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 105

using namespace std;

int N;
int MAP[MAX];
int visited[MAX], Fin[MAX];
int ans;
vector<int> answer;

void Get_answer(int u, int v)
{
	ans++;
	answer.push_back(v);
	if (u == v)return;
	Get_answer(u, MAP[v]);
}

void search(int idx)
{
	visited[idx] = 1;
	int next = MAP[idx];
	if (!visited[next])search(next);
	else
	{
		if (!Fin[next])Get_answer(idx, next);
	}
	Fin[idx] = 1;
}

int main()
{

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> MAP[i];
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])search(i);
	}

	cout << ans << endl;

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}

	return 0;
}