#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N, K;
queue<pair<int, int>> Q;
int check[500001][2];

bool inRange(int x) {return (0 <= x && x <= 500000);}

int main()
{
    cin >> N >> K;
    if (N == K) {
        cout << 0 << endl;
        return 0;
    }
    memset(check, -1 ,sizeof(check));
    int ans = 987654321;
    Q.push({N, 0});
    check[N][0] = 1;

    while (!Q.empty())
    {
        int X = Q.front().first;
        int t = Q.front().second;
        Q.pop();

        if (K + (t * (t + 1) / 2) > 500000)continue;

        int next[3] = {X - 1, X + 1, 2 * X};
        for (int i = 0; i < 3; i++)
        {
            int nx = next[i];
            int ch_ = (t + 1) % 2 == 1;
            if (inRange(nx) && check[nx][ch_] == -1)
            {
                Q.push({nx, t + 1});
                check[nx][ch_] = t + 1;
            }
        }
    }

    for (int i = 0; i < 500000; i++)
	{
		int nk = K + i * (i + 1) / 2;
		if (nk > 500000)
		{
			break;
		}

		if (check[nk][i % 2] != -1 && check[nk][i % 2] <= i)
		{
			
			cout << i << endl;
			return 0;
		}
	}

    cout << -1 << endl;
    return 0;
}