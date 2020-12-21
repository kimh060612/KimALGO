#include <iostream>
#include <fstream>
#define MAX 105

using namespace std;

ifstream fin;
ofstream fout;

int ADJ[MAX][MAX];
int visited[MAX], distance_[MAX];
int N, M;

void Search(int Cnt,int id)
{
	visited[id] = 1;

	if (distance_[id])distance_[id] = Cnt > distance_[id] ? distance_[id] : Cnt;
	else distance_[id] = Cnt;

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0 && ADJ[id][i]) 
		{
			Search(Cnt + 1, i); 
		}
	}
	visited[id] = 0;
}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		ADJ[a][b] = 1;
		ADJ[b][a] = 1;
	}

	int min = 987654321,answer = 0;

	for (int i = 1; i <= N; i++)
	{
		Search(0, i);
		int Sum = 0;
		for (int j = 1; j <= N; j++)
		{
			Sum += distance_[j];
			distance_[j] = 0;
		}
		if (min > Sum)
		{
			min = Sum;
			answer = i;
		}
	}

	cout << answer << endl;

	fin.close();
	fout.close();
	return 0;
}