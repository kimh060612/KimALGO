#include <iostream>
#include <fstream>
#include <queue>
#include <string.h>
#define MAX 101

using namespace std;

struct Coord
{
	int y, x, num;
	bool operator <(Coord a)const { return num > a.num; }
};

ifstream fin;
ofstream fout;

int N, M;
int MAP[MAX][MAX];
int PATH[MAX][MAX];
int dx[5] = { 1,-1,0,0 };
int dy[5] = { 0,0,1,-1 };

priority_queue<Coord> Q;

void input()
{
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
	{
		char tmp[110];
		cin >> tmp;
		for (int j = 0; j < strlen(tmp); j++)
		{
			MAP[i][j + 1] = tmp[j] - 48;
			PATH[i][j + 1] = 987654321;
		}
	}
}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	input();
	
	PATH[1][1] = 0;
	Q.push({1,1,0});

	while (1)
	{
		if (Q.empty())break;
		int y = Q.top().y;
		int x = Q.top().x;
		int cost = Q.top().num;
		Q.pop();

		if (PATH[y][x] < cost)continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i]; int ny = y + dy[i];

			if (nx >= 1 && ny >= 1 && nx <= M && ny <= N)
			{
				if (PATH[ny][nx] > cost + MAP[ny][nx])
				{
					PATH[ny][nx] = cost + MAP[ny][nx];
					Q.push({ ny,nx,PATH[ny][nx] });
				}
			}

		}
	}

	cout << PATH[N][M] << endl;

	fin.close();
	fout.close();
	return 0;
}