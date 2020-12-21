#include <iostream>
#define min(a, b) a > b ? b : a
#define INF 300001

using namespace std;

int N;
int Seq[INF], DP[INF];

int main()
{
	cin >> N;

	int tmp = 1, iter = 1;
	Seq[1] = 1;
	while (N >= tmp)
	{
		iter++;
		tmp = (iter*(iter + 1)*(iter + 2)) / 6;
		Seq[iter] = tmp;
	}
	Seq[iter] = 0;
	iter--;
	
	for (int i = 1; i <= N; i++)DP[i] = INF;
	for (int i = 1; i <= iter; i++) DP[Seq[i]] = 1;

	for (int i = 1; i <= iter; i++)
	{
		for (int j = Seq[i]; j <= N; j++)
		{
			DP[j] = min(DP[j], DP[j - Seq[i]] + 1);
		}
	}

	cout << DP[N] << endl;

}