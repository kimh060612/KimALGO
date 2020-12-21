#include <iostream>
#include <fstream>
#define MAX 1001

using namespace std;

ifstream fin;
ofstream fout;

int N;
int Seq[MAX], DP[MAX], DPB[MAX];

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Seq[i];
	}

	int answer = -987654321;

	for (int i = 1; i <= N; i++)
	{
		DP[i] = DPB[i] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (Seq[i] > Seq[j] && DP[i] < DP[j] + 1)DP[i] = DP[j] + 1;
		}
	}

	for (int i = N; i >= 1; i--)
	{
		for (int j = i; j <= N; j++)
		{
			if (Seq[i] > Seq[j] && DPB[i] < DPB[j] + 1)DPB[i] = DPB[j] + 1;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		answer = max(answer, DP[i] + DPB[i] - 1);
	}

	cout << answer << endl;

	fin.close();
	fout.close();
	return 0;
}