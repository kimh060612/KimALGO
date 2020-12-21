#include <iostream>
#include <memory.h>

using namespace std;

int N, A[201];
int DP[201];

int LIS(int index)
{
	int &ret = DP[index];
	if (ret != 0)return ret;

	for (int i = index + 1; i <= N; i++)
	{
		if (A[i] > A[index])
		{
			int tmp = LIS(i);
			if (tmp > ret)ret = tmp;
		}
	}
	++ret;
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		memset(DP, 0, sizeof(DP));
		int tmp = LIS(i);
		if (answer < tmp)answer = tmp;
	}

	cout << (N - answer) << endl;
	return 0;
}