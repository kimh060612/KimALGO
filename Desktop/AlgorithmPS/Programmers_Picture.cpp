#include <string>
#include <vector>
#include <map>

using namespace std;

// 1 ~ 8: A ~ T
int position[10], occupied[10];
char ItoC[8] = { 'A','C','F','J','M','N','R','T' };

int dfs(int depth, int pos, vector<string> &condition)
{
	position[depth] = pos;
	occupied[pos] = 1;

	if (depth == 8)
	{
		bool isFit = true;
		for (int i = 0; i < condition.size(); i++)
		{
			int p, t;
			for (int j = 0; j < 8; j++)
			{
				if (condition[i][0] == ItoC[j]) p = j + 1;
				if (condition[i][2] == ItoC[j]) t = j + 1;
			}
			char cond = condition[i][3];
			int num = condition[i][4] - '0';

			if (cond == '=') {
				if (abs(position[p] - position[t]) - 1 != num) isFit = false;
			}
			else if (cond == '>') {
				if (abs(position[p] - position[t]) - 1 <= num) isFit = false;
			}
			else if (cond == '<') {
				if (abs(position[p] - position[t]) - 1 >= num) isFit = false;
			}
		}
		position[depth] = 0;
		occupied[pos] = 0;
		return isFit ? 1 : 0;
	}

	int res = 0;
	for (int i = 1; i <= 8; i++)
	{
		if (!occupied[i]) res += dfs(depth + 1, i, condition);
	}

	position[depth] = 0;
	occupied[pos] = 0;

	return res;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	int answer = 0;

	for (int i = 1; i <= 8; i++)
	{
		answer += dfs(1, i, data);
	}

	return answer;
}