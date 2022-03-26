#include <string>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < scoville.size(); i++) pq.push(scoville[i]);

	int tmp = 0;
	while (!pq.empty())
	{
		int x = pq.top();
		pq.pop();

		if (x >= K) break;
		if (pq.size() == 0) {
			tmp = -1;
			break;
		}
		else {
			tmp++;
			int l = x + 2 * pq.top();
			pq.pop();
			pq.push(l);
		}
	}

	answer = tmp;
	return answer;
}