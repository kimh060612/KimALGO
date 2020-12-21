#include <iostream>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }
int A[11];

int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	int tmp = K, answer = 0;
	for (int i = N; i >= 1; i--)
	{
		answer += tmp / A[i];
		tmp %= A[i];
	}

	cout << answer << endl;
	return 0;
}