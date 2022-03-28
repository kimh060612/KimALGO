#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;

	vector<int> lost_new;
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (int i = 0; i < lost.size(); i++)
	{
		bool flag = true;
		for (int j = 0; j < reserve.size(); j++)
		{
			if (reserve[j] == lost[i]) {
				flag = false;
				reserve.erase(reserve.begin() + j);
				break;
			}
		}
		if (flag) lost_new.push_back(lost[i]);
	}

	answer = n - lost_new.size();
	for (int i = 0; i < lost_new.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (lost_new[i] - 1 == reserve[j]) {
				answer++;
				reserve.erase(reserve.begin() + j);
				break;
			}
			else if (lost_new[i] + 1 == reserve[j]) {
				answer++;
				reserve.erase(reserve.begin() + j);
				break;
			}
		}
	}

	return answer;
}