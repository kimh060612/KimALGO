#include <iostream>
#include <algorithm>
#include <fstream>
#define MAX 1000001
#define INF 987654321
#define min(a, b) a > b ? b : a

using namespace std;

ifstream fin;
ofstream fout;

int DP[MAX];

/*int MAKE_One(int num)
{

	if (num == 1)return 0;

	int &ret = DP[num];

	if (ret != INF)return ret;

	if (num % 3 == 0)ret = min(ret, MAKE_One(num / 3) + 1);
	if (num % 2 == 0)ret = min(ret, MAKE_One(num / 2) + 1);
	ret = min(ret, MAKE_One(num - 1) + 1);

}*/

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int n;
	cin >> n;
	
	fill(DP, DP + n + 1, INF);

	DP[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		if (i % 3 == 0)DP[i] = min(DP[i], DP[i / 3] + 1);
		if (i % 2 == 0)DP[i] = min(DP[i], DP[i / 2] + 1);
		DP[i] = min(DP[i], DP[i - 1] + 1);
	}

	cout << DP[n] << endl;

	fin.close();
	fout.close();
}