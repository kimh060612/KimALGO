/*
문제 유형: 간단한 백 트래킹(DFS)유형
헷갈린점: 어떻게 퀸이 퀸을 잡아먹는 것을 표현할까?
구현 아이디어: 구글 출처, Queen의 위치를 인덱스가 행, 열을 값에 넣어서 구현하고 공식을 세워서 퀸이 퀸을 잡아 먹는 것을 구현.
느낀점: 백준 개객기 왜 15개 전부 시도해서 맞게 나오는데 틀렸다고 하냐??
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

ifstream fin;
ofstream fout;

int queen[100000];
int N,cnt;

void Q(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (queen[i] == queen[x] || abs(queen[i] - queen[x]) == abs(i - x))return;
	}

	if (x == N - 1)
	{
		cnt++;
		return;
	}
	
	for (int i = 0; i < N; i++)
	{
		queen[x + 1] = i;
		Q(x + 1);
	}
}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	fin >> N;

	for (int i = 0; i < N; i++)
	{
		queen[0] = i;
		Q(0);
	}
	
	fout << cnt << endl;

	fin.close();
	fout.close();
	return 0;
}
