#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> M;

vector<string> solution(vector<string> record) {
	vector<string> answer;

	for (int i = 0; i < record.size(); i++)
	{
		string con = record[i];
		int index = con.find(' ', 0);
		string el = con.substr(0, index);
		int index_2 = con.find(' ', index + 1);
		string uid = con.substr(index + 1, index_2 - index - 1);
		string name = con.substr(index_2 + 1, record[i].size() - index_2 - 1);
		if (el != "Leave")M[uid] = name;
	}

	for (int i = 0; i < record.size(); i++)
	{
		string con = record[i];
		int index = con.find(' ', 0);
		string el = con.substr(0, index);
		int index_2 = con.find(' ', index + 1);
		string uid = con.substr(index + 1, index_2 - index - 1);
		string tmp = M[uid];
		if (el == "Enter") {
			tmp += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
			answer.push_back(tmp);
		}
		else if (el == "Leave") {
			tmp += "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
			answer.push_back(tmp);
		}
	}

	return answer;
}

int main()
{
	int n;
	cin >> n;
	vector<string> K;
	K.resize(n + 1, "");
	for (int i = 0; i < n; i++) cin >> K[i];
	vector<string> ans = solution(K);
	for (int i = 0; i < n; i++) cout << ans[i] << endl;
	return 0;
}