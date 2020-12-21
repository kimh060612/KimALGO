#include <iostream>
#include <windows.h>
#define MAX 100

using namespace std;

int N;
long long DP[MAX];

long long FIBO(int n)
{
	long long &ret = DP[n];
	if (ret != 0)return ret;
	if (n == 0)return 0;

	ret = FIBO(n - 1) + FIBO(n - 2);
	return ret;
}

int main()
{
	cin >> N;

	DP[0] = 0;
	DP[1] = 1;

	cout << FIBO(N) <<endl;
	system("PAUSE");

	return 0;
}