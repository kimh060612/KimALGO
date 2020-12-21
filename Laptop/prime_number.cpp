#include <iostream>
#include <fstream>
#define INF 101

using namespace std;

ifstream fin;
ofstream fout;

int N;

bool Is_Prime(int n)
{
	if (n <= 1)return false;

	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)return false;
	}
	return true;
}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int answer = 0;

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		if (Is_Prime(a))answer++;
	}

	cout << answer << endl;

	fin.close();
	fout.close();
}