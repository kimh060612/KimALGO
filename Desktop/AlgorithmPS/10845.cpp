#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int N;
	stack <int> St;
	queue<int> Q;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		string S;
		cin >> S;
		if (S == "push")
		{
			int a;
			cin >> a;
			Q.push(a);
		}
		else if (S == "pop")
		{
			if (Q.empty()) cout << -1 << endl;
			else {
				cout << Q.front() << endl;
				Q.pop();
			}
		}
		else if (S == "front")
		{
			if (Q.empty()) cout << -1 << endl;
			else cout << Q.front() << endl;
		}
		else if (S == "back")
		{
			if (Q.empty()) cout << -1 << endl;
			else cout << Q.back() << endl;
		}
		else if (S == "empty")
		{
			cout << Q.empty() << endl;
		}
		else if (S == "size")
		{
			cout << Q.size() << endl;
		}
	}
	return 0;
}