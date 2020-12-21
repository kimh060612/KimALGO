#include <iostream>
#include <fstream>
#define MAX 100001

using namespace std;

ifstream fin;
ofstream fout;

int visited[MAX], Fin[MAX];
int MAP[MAX];
int num_case,ans;

void clear(int num)
{
	for (int i = 1; i <= num; i++)
	{
		MAP[i] = 0;
		visited[i] = 0;
		Fin[i] = 0;
	}
}

void Get_answer(int u, int v)
{
	ans++;
	if (u == v)return;
	Get_answer(u,MAP[v]);
}

void Search(int idx)
{
	visited[idx] = 1;
	int next = MAP[idx];

	if (!visited[next])Search(next);
	else
	{
		if (!Fin[next])Get_answer(idx,next);
	}
	Fin[idx] = 1;
}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	fin >> num_case;

	for (int i = 0; i < num_case; i++)
	{
		ans = 0;
		int n;
		fin >> n;
		for (int j = 1; j <= n; j++) 
		{
			fin >> MAP[j];
		}

		for (int j = 1; j <= n; j++)
		{
			if (!visited[j])Search(j);
		}

		fout << n - ans << endl;

		clear(n);

	}

	fin.close();
	fout.close();
	return 0;
}


