#include <iostream>
#include <string>

using namespace std;

long long DP[50];

int main()
{
	string s;
	cin >> s;

	DP[0] = 1;
	DP[1] = 1;

	for (int i = 1; i < s.size(); i++)
	{
		string tmp = s.substr(i - 1, 2);
		int p = tmp[0] - 48;
		int c = tmp[1] - 48;
		if (c != 0) DP[i + 1] += DP[i];
		
		if (p != 0 && 10 * p + c <= 34) DP[i + 1] += DP[i - 1];

		if (DP[i] == 0) break;
	}

	cout << DP[s.size()] << endl;

	return 0;
}