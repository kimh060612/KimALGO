#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> P, C;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	for (int i = 0; i < completion.size(); i++) C[completion[i]] = 0;
	for (int i = 0; i < completion.size(); i++) C[completion[i]] += 1;

	for (int i = 0; i < participant.size(); i++) P[participant[i]] = 0;
	for (int i = 0; i < participant.size(); i++) P[participant[i]] += 1;

	for (auto iter = C.begin(); iter != C.end(); iter++)
	{
		P[iter->first] -= iter->second;
	}

	for (auto iter = P.begin(); iter != P.end(); iter++)
	{
		if (iter->second != 0) answer = iter->first;
	}

	return answer;
}