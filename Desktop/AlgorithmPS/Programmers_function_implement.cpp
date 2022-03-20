#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int N = progresses.size();
	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++)
	{
		Q.push({ progresses[i], speeds[i] });
	}

	for (int t = 1;; t++)
	{
		int cnt = 0;
		while (1) {
			int x = Q.front().first;
			int s = Q.front().second;
			if (100 <= x + s * t) {
				cnt++;
				Q.pop();
			}
			else break;
		}
		if (cnt != 0) answer.push_back(cnt);
		if (Q.empty())break;
	}

	return answer;
}