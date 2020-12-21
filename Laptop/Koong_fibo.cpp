#include <iostream>

using namespace std;

long long Fibo[68];

int main()
{
	int t;
	cin >> t;
	Fibo[0] = 1;
	Fibo[1] = 1;
	Fibo[2] = 2;
	Fibo[3] = 4;

	for (int i = 4; i <= 67; i++)
	{
		Fibo[i] = Fibo[i - 1] + Fibo[i - 2] + Fibo[i - 3] + Fibo[i - 4];
	}

	for (int i = 1; i <= t; i++)
	{
		int N;
		cin >> N;
		cout << Fibo[N] << endl;
	}
	return 0;
}