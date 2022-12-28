#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	queue<int> Q;
	vector<pair<int, int>> A;

	for (int i = 0; i < priorities.size(); i++) A.push_back({ i, priorities[i] });

	while (A.size() != 0)
	{
		bool flag = false;
		for (int j = 1; j < A.size(); j++)
		{
			if (A[0].second < A[j].second) {
				flag = true;
				break;
			}
		}
		if (flag) {
			pair<int, int> tmp = A[0];
			for (int j = 1; j < A.size(); j++)
			{
				A[j - 1] = A[j];
			}
			A[A.size() - 1] = tmp;
		}
		else {
			Q.push(A[0].first);
			A.erase(A.begin());
		}
	}

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		answer++;
		if (x == location) break;
	}

	return answer;
}