#include <iostream>
#include <fstream>
#include <queue>
#include <memory.h>
#define MAX 1001

using namespace std;

ifstream fin;
ofstream fout;

int N, M;
int MAP[MAX][MAX], check[MAX][MAX];
queue<pair<int, int>> Q;
int dx[5] = {1,-1,0,0};
int dy[5] = {0,0,1,-1};

bool IS_Full()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (MAP[i][j] == 0)return false;
		}
	}
	return true;
}

void input()
{
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 1)
			{
				check[i][j] = 1;
				Q.push(make_pair(i, j));
			}
		}
	}
}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	input();

	int answer = 0;

	while (1)
	{
		if (Q.empty())break;

		int num = Q.size();
		for (int i = 0; i < num; i++)
		{
			int Y = Q.front().first;
			int X = Q.front().second;
			Q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = X + dx[i];
				int ny = Y + dy[i];

				if (nx >= 1 && ny >= 1 && nx <= M && ny <= N)
				{
					if (MAP[ny][nx] == 0 && !check[ny][nx])
					{
						Q.push(make_pair(ny, nx));
						check[ny][nx] = 1;
						MAP[ny][nx] = 1;
					}
				}
				
			}
		}
		answer++;
	}

	if (!IS_Full())cout << -1 << endl;
	else cout << answer - 1 << endl;

	fin.close();
	fout.close();
	return 0;
}