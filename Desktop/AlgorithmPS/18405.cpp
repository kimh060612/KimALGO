#include <iostream>
#include <vector>       // for virus
#include <queue>        // for BFS
#include <tuple>
#include <algorithm>    // for sorting
using namespace std;

static int N, K, S, X, Y, test[201][201];
static vector<tuple<int, int, int>> virus;	// {num, y, x}
static constexpr int moving[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isValid(int y, int x) {
	return (1 <= y && y <= N) && (1 <= x && x <= N);
}

void simulation() {
	queue<tuple<int, int, int>> q;
	for (const auto& v : virus) q.push(v);
	
	int prevVirusNum = 0;
	while(S != 0 && !q.empty()) {
		int vNum, curY, curX;
		tie(vNum, curY, curX) = q.front();
		q.pop();
		
                // if every virus has got its turn then subtract 'S'.
		if (prevVirusNum > vNum)    
			if (--S <= 0) break;    // End simulation as soon as 'S' reaches 0.
		prevVirusNum = vNum;
		
		for (int i = 0; i < 4; ++i) {
			int newY = curY + moving[i][0], newX = curX + moving[i][1];
			if (isValid(newY, newX) && test[newY][newX] == 0) {
				test[newY][newX] = vNum;
				q.push({vNum, newY, newX});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> K;
	for (int y = 1; y <= N; ++y)
		for (int x = 1; x <= N; ++x) {
			cin >> test[y][x];
			if (test[y][x] != 0) virus.push_back({test[y][x], y, x});
		}
	cin >> S >> Y >> X;    // X is row and Y is col in this problem.
	sort(virus.begin(), virus.end());    // Sort by first elem (virus num) of tuple.  
	simulation();
	cout << test[Y][X] << '\n';
}