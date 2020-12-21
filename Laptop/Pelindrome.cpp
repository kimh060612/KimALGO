#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string S;
int N;

bool Pel(int index)
{
	for (int i = 0;  index + i < N - i - 1; i++)
	{
		if (S[index + i] != S[N - i - 1])return false;
	}
	return true;
}

int main()
{
	cin >> S;
	N = S.size();

	int res = 0;

	for (int i = 0; i < N; i++)
	{
		if (Pel(i)) { res = N + i; break; }
	}

	cout << res << endl;
	return 0;

}