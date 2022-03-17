#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &i, const string &j)
{
	string k = i + j;
	string l = j + i;
	return k < l;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> k;
	for (int i = 0; i < numbers.size(); i++)
		k.push_back(to_string(numbers[i]));

	sort(k.begin(), k.end(), compare);
	reverse(k.begin(), k.end());

	for (int i = 0; i < k.size(); i++)
		answer += k[i];

	if (answer[0] == '0')
		return "0";

	return answer;
}
