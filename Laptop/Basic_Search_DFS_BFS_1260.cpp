/*
문제 유형: 너무나도 단순한 DFS,BFS문제 진짜 문제에서 대놓고 명시함
헷갈린점: 있겠냐?
구현 아이디어: 단순한 DFS, BFS
느낀점: 왜 이거 ㅅㅂ 정답율 30%? 뇌 없? 
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int num_Vertex, num_Edge;

vector<int> RES_DFS;
vector<int> RES_BFS;
vector<vector<int>> Link_Edge;
vector<int> Check_Arr;
queue<int> Q;

void DFS(int now)
{
	vector<int> Search_res;
	Check_Arr[now] = 1;
	RES_DFS.push_back(now);

	vector<int>::iterator it;
	int count = 0;
	for (it = Link_Edge[now].begin(); it != Link_Edge[now].end(); ++it)
	{
		if (!Check_Arr[*it])DFS(*it);
	}
}

int main()
{
	int S;

	cin >> num_Vertex >> num_Edge >> S;

	Link_Edge.resize(num_Vertex);
	Check_Arr.assign(num_Vertex, 0);

	for (int i = 0; i < num_Edge; i++)
	{
		int a, b;
		cin >> a >> b;
		Link_Edge[a-1].push_back(b-1);
		Link_Edge[b-1].push_back(a-1);
	}

	for (int i = 0; i < num_Vertex; i++)
	{
		sort(Link_Edge[i].begin(), Link_Edge[i].end());
	}

	DFS(S-1);

	Check_Arr.assign(num_Vertex, 0);

	Q.push(S-1);
	Check_Arr[S-1] = 1;
	while (1) 
	{
		if (Q.size() == 0)break;

		vector<int>::iterator it;
		for (it = Link_Edge[Q.front()].begin(); it != Link_Edge[Q.front()].end(); ++it)
		{
			if (!Check_Arr[*it])
			{
				Q.push(*it);
				Check_Arr[*it] = 1;
			}
		}
		RES_BFS.push_back(Q.front());
		Q.pop();
	}

	vector<int>::iterator it;
	for (it = RES_DFS.begin(); it != RES_DFS.end(); ++it)
	{
		cout << *it + 1 << " ";
	}
	cout << endl;
	for (it = RES_BFS.begin(); it != RES_BFS.end(); ++it)
	{
		cout << *it + 1 << " ";
	}

}
