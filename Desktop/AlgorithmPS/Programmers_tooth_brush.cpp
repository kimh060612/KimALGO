#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m, parent, profit;

void travel(string seller, vector<string> &enroll, int won)
{
	if (won == 0) return;

	if (parent[seller] == 0) {
		profit[seller] += (won - won / 10);
		profit["center"] += (int)(won / 10);
		return;
	}

	profit[seller] += (won - won / 10);
	travel(enroll[parent[seller] - 1], enroll, (int)(won / 10));
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer;

	m["cetner"] = 0;
	profit["center"] = 0;
	for (int i = 0; i < enroll.size(); i++)
	{
		m[enroll[i]] = i + 1;
		profit[enroll[i]] = 0;
	}

	for (int i = 0; i < referral.size(); i++)
	{
		string p = referral[i];
		if (p == "-") p = "center";
		parent[enroll[i]] = m[p];
	}

	for (int i = 0; i < seller.size(); i++)
	{
		travel(seller[i], enroll, amount[i] * 100);
	}

	for (int i = 0; i < enroll.size(); i++)
	{
		answer.push_back(profit[enroll[i]]);
	}

	return answer;
}