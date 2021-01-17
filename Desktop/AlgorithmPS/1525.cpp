#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool InRange(int y, int x) {return (0 <= x && x < 3 && 0 <= y && y < 3);}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long start = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int t;
            cin >> t;
            if (t == 0)t = 9;
            start = start * 10 + t;
        }
    }

    map<int, int> dist;
    queue<int> Q;
    Q.push(start);
    dist[start] = 0;

    while (!Q.empty())
    {
        long long A = Q.front();
        string now = to_string(A);
        int index = now.find('9');
        Q.pop();
        int x = index % 3;
        int y = index / 3;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (InRange(ny, nx))
            {
                string next = now;
                swap(next[y * 3 + x], next[ny * 3 + nx]);
                int num = stoi(next);
                if (dist.count(num) == 0)
                {
                    dist[num] = dist[A] + 1;
                    Q.push(num);
                }
            }
        }
    } 

    if (dist.count(123456789) == 0)
        cout << "-1" << "\n";
    else
        cout << dist[123456789] << "\n";

    return 0;
}
