#include <iostream>
#include <fstream>
#include <memory.h>
#define MAX 1010
#define INF 987654321
#define min(a,b) a> b ? b : a

using namespace std;

ifstream fin;
ofstream fout;

int N;
int MAP[MAX][5];
int DP[MAX][5];

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> MAP[i][j];
		}
	}
}


int Search(int now,int color)
{
	int &ret = DP[now][color];
	if (ret != -1)return ret;
	if (now > N)return 0;

	ret = INF;
	for (int i = 0; i < 3; i++)
	{
		if(color != i)ret = min(ret, Search(now+1,i)+MAP[now][i]);
	}

	return ret;
}

int main()
{
	fin.open("input.txt");
	fout.open("outptut.txt");

	input();
	
	memset(DP, -1, sizeof(DP));

	int answer = 987654321;
	for (int i = 0; i < 3; i++)
	{
		int tmp = Search(1,i);
		if (answer > tmp)answer = tmp;
	}

	cout << answer << endl;

	fin.close();
	fout.close();
	return 0;
}

