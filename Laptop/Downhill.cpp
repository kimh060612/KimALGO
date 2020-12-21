#include <iostream>
//#include <fstream>
#include <memory.h>
#define INF 501

using namespace std;

//ifstream fin;
//ofstream fout;

int N, M;
int A[INF][INF];
int DP[INF][INF];

int dx[5] = { 1,-1,0,0 };
int dy[5] = { 0,0,1,-1 };

int Search(int y, int x)
{
	int &ret = DP[y][x];
	if (ret != -1)return ret;
	if (x < 1 || y < 1 || x > M || y > N)return 0;
	if (x == M && y == N)return 1;

	ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int NY = y + dy[i];
		int NX = x + dx[i];
		if (A[NY][NX] < A[y][x])
		{
			ret += Search(NY, NX);
		}
	}

	return ret;
}

int main()
{
	//fin.open("input.txt");
	//fout.open("output.txt");

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> A[i][j];
		}
	}

	memset(DP, -1, sizeof(DP));

	cout << Search(1,1) << endl;

	//fin.close();
	//fout.close();
	return 0;
}
