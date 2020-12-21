#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

string DP[1001];

string bigNumAdd(string num1, string num2)
{
	long long sum = 0;
	string result;

	while (!num1.empty() || !num2.empty() || sum)
	{

		if (!num1.empty())
		{
			sum += num1.back() - '0';
			num1.pop_back();
		}

		if (!num2.empty())
		{
			sum += num2.back() - '0';
			num2.pop_back();
		}

		result.push_back((sum % 10) + '0');
		sum /= 10;
	}

	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	DP[0] = "1";
	DP[1] = "1";

	for (int i = 2; i <= 250; i++)
		DP[i] = bigNumAdd(bigNumAdd(DP[i - 2], DP[i - 2]), DP[i - 1]);

	int N;
	while (cin >> N) cout << DP[N] << "\n";


	return 0;
}