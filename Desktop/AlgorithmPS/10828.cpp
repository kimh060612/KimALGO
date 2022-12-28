#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int N;
	stack <int> St;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		string S;
		cin >> S;
		if (S == "push")
		{
			int a;
			cin >> a;
			St.push(a);
		}
		else if (S == "pop")
		{
			if (St.empty()) cout << -1 << endl;
			else {
				cout << St.top() << endl;
				St.pop();
			}
		}
		else if (S == "top")
		{
			if (St.empty()) cout << -1 << endl;
			else cout << St.top() << endl;
		}
		else if (S == "empty")
		{
			cout << St.empty() << endl;
		}
		else if (S == "size")
		{
			cout << St.size() << endl;
		}
	}
	return 0;
}