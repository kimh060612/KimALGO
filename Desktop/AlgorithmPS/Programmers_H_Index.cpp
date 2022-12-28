#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end());
	reverse(citations.begin(), citations.end());

	int h = 0;
	for (int i = 0; i < citations[0]; i++)
	{
		int cnt = 0, k = i;
		for (int j = 0; j < citations.size(); j++)
		{
			if (citations[j] >= k) cnt++;
		}
		if (cnt >= k) h = k >= h ? k : h;
	}

	answer = h;
	return answer;
}