#include <iostream>
#include <string>
#include <stack>

using namespace std;

string S;
stack<int> match;
int MAXLEN;
int End_braket[60];

int Decompress(int s, int e)
{
	int answer = 0;
	for (int i = s; i < e; i++)
	{
		if (S[i] == '(')
		{
			int k = atoi(&S[i-1]);
			answer += k * Decompress(i + 1, End_braket[i]) - 1;
			i = End_braket[i];
			continue;
		}
		answer++;
	}
	return answer;
}

int main()
{
	cin >> S;
	MAXLEN = S.size();

	for (int i = 0; i < MAXLEN; i++)
	{
		if (S[i] == '(')match.push(i);
		if (S[i] == ')')
		{
			End_braket[match.top()] = i;
			match.pop();
		}
	}
	cout << Decompress(0 ,MAXLEN) << endl; 
	return 0;
}