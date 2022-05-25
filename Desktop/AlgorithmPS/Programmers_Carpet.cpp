#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	int area = brown + yellow;
	for (int i = 3; i <= brown / 2; i++)
	{
		if (area % i == 0) {
			int H = area / i;
			if (yellow == (H - 2) * (i - 2)) {
				int h = H > i ? H : i;
				int w = H < i ? H : i;
				answer.push_back(h);
				answer.push_back(w);
				break;
			}
		}
	}

	return answer;
}