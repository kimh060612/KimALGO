#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> visited;

bool InRange(int y, int x) { return (0 <= y && y < N) && (0 <= x && x < M); }
int max(int a, int b) { return a > b ? a : b; }

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int BFS(int y, int x, int k, vector<vector<int>> &picture)
{
	queue<pair<int, int>> Q;
	Q.push({ y, x });
	visited[y][x] = 1;

	int result = 0;
	while (!Q.empty())
	{
		int now_y = Q.front().first;
		int now_x = Q.front().second;
		Q.pop();

		result += 1;
		for (int i = 0; i < 4; i++)
		{
			int nx = now_x + dx[i];
			int ny = now_y + dy[i];
			if (InRange(ny, nx) && !visited[ny][nx] && picture[ny][nx] == k) {
				visited[ny][nx] = 1;
				Q.push({ ny, nx });
			}
		}
	}

	return result;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	N = m;
	M = n;
	visited.assign(N, vector<int>(M, 0));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (picture[i][j] != 0 && visited[i][j] == 0) {
				int tmp = BFS(i, j, picture[i][j], picture);
				max_size_of_one_area = max(max_size_of_one_area, tmp);
				number_of_area++;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}