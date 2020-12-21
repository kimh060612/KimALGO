#include <iostream>
#include <fstream>
#include <queue>
#define MAX 105

using namespace std;

ifstream fin;
ofstream fout;

struct Coord
{
	int x, y;
};

int N;
int MAP[MAX][MAX], check[MAX][MAX];
int New_MAP[MAX][MAX], check2[MAX][MAX];
int dx[5] = {0,0,1,-1};
int dy[5] = {1,-1,0,0};
queue<Coord> Q;

void clear()
{
	for (;;)
	{
		if (Q.empty())break;
		Q.pop();
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			check2[i][j] = 0;
		}
	}
}

void input()
{
	fin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			fin >> MAP[i][j];
		}
	}
}


void LAND_Seperate(int x,int y, int num)
{
	if (x < 1 || y < 1 || x > N || y > N)return;

	check[y][x] = 1;
	New_MAP[y][x] = num;

	if (MAP[y][x - 1] && !check[y][x - 1])LAND_Seperate(x-1,y,num);
	if (MAP[y - 1][x] && !check[y-1][x])LAND_Seperate(x,y-1,num);
	if (MAP[y][x + 1] && !check[y][x + 1])LAND_Seperate(x+1,y,num);
	if (MAP[y + 1][x] && !check[y + 1][x])LAND_Seperate(x,y+1,num);
}

int num = 1;

void launch()
{
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			if (!check[y][x] && MAP[y][x])
			{
				LAND_Seperate(x, y, num);
				num++;
			}
		}
	}
}

int Bridge(int Island)
{
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			if (New_MAP[y][x] == Island)
			{
				Coord A;
				A.x = x; A.y = y;
				Q.push(A);
				check2[y][x] = 1;
			}
		}
	}

	int path = 0;

	while (!Q.empty())
	{
		int S = Q.size();
		for (int i = 0; i < S; i++)
		{
			int x = Q.front().x;
			int y = Q.front().y;
			Q.pop();

			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
				{
					if (New_MAP[ny][nx] != 0 && New_MAP[ny][nx] != Island)return path;
					else if (!check2[ny][nx] && New_MAP[ny][nx] == 0)
					{
						Coord A;
						A.x = nx; A.y = ny;
						Q.push(A);
						check2[ny][nx] = 1;
					}
				}
			}
		}
		path++;
	}

}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int min = 987654321;

	input();

	launch();

	for (int i = 1; i < num; i++)
	{
		int tmp = Bridge(i);
		min = tmp < min ? tmp : min;
		clear();
	}

	fout << min << endl;

	fin.close();
	fout.close();
	return 0;
}