#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<string, int> visited;

bool compare(string a, string b)
{
	int n = a.size(), num = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i]) num++;
	}
	if (num == a.size() - 1) return true;
	else return false;
}

int min(int a, int b) { return a < b ? a : b; }

int bfs(string now, string &target, vector<string> &words)
{
	queue<pair<string, int>> Q;
	Q.push({ now, 1 });
	int answer = 987654321;

	while (!Q.empty())
	{
		string x = Q.front().first;
		int n = Q.front().second;
		Q.pop();

		if (x == target) {
			answer = min(answer, n);
		}

		visited[x] = 1;
		for (int i = 0; i < words.size(); i++)
		{
			if (visited.find(words[i]) == visited.end() && compare(words[i], x))
			{
				Q.push({ words[i], n + 1 });
			}
		}
	}
	return answer;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 987654321;
	answer = bfs(begin, target, words);
	if (answer == 987654321) answer = 0;
	return answer;
}