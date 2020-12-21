#include <iostream>
#include <fstream>
#define MAX 110

using namespace std;

ifstream fin;
ofstream fout;

int N;
int MAP[MAX][MAX], check[MAX][MAX], DP[MAX][MAX];

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> MAP[i][j];
		}
	}
}

long long JUMP(int x,int y)
{
	long long answer = 0;
	if (x == N && y == N)return 1;
	if (MAP[y][x] == 0)return 0;
	if (check[y][x] || DP[y][x] != 0)return DP[y][x];

	check[y][x] = 1;

	if (x + MAP[y][x] <= N && !check[y][x + MAP[y][x]]) 
	{
		answer += JUMP(x + MAP[y][x], y);
	}
	if (y + MAP[y][x] <= N && !check[y + MAP[y][x]][x]) 
	{
		answer += JUMP(x, y + MAP[y][x]);
	}

	check[y][x] = 0;
	DP[y][x] = DP[y][x] > answer ? DP[y][x] : answer;

	return answer;
}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	input();

	cout << JUMP(1,1) << endl;

	fin.close();
	fout.close();
	return 0;
}
