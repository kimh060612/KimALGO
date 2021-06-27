#include <iostream>
#include <queue>
#include <string>

using namespace std;

bool pelindrome(string S)
{
	queue<int> Q;
	queue<int> Q_re;
	for (int i = 0; i < S.size(); i++)
	{
		int k = S[i] - 48;
		int l = S[S.size() - i - 1] - 48;
		Q.push(k);
		if (i == 0 && l == 0)continue;
		else Q_re.push(l);
	}

	while (!Q.empty() || !Q_re.empty())
	{
		int one = Q.front();
		int two = Q_re.front();
		if (one != two) break;
		Q.pop();
		Q_re.pop();
	}

	if (Q.empty() && Q_re.empty()) return true;
	else return false;
}

int main()
{
	string S;
	while (1)
	{
		cin >> S;
		if (S == "0")break;
		if (pelindrome(S)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}