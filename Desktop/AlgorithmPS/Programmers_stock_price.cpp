#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for (int i = 0; i < prices.size(); i++)
	{
		int index = 0;
		bool flag = false;
		for (int j = i + 1; j < prices.size(); j++)
		{
			if (prices[i] > prices[j]) {
				index = j - i;
				flag = true;
				break;
			}
		}
		if (!flag) index = prices.size() - 1 - i;
		answer.push_back(index);
	}

	return answer;
}