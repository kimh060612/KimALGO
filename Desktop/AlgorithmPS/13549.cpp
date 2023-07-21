#include <iostream>
#include <queue>
#define MAX 100000

using namespace std;
using iip = pair<int, int>;

int N, K;
int dist[MAX + 5];

int main()
{
    cin >> N >> K;
    priority_queue<iip> pq;
    pq.push({ 0, N });
    for (int i = 0; i <= MAX; i++) {
        dist[i] = 987654321;
    }
    dist[N] = 0;

    while (!pq.empty()) {
        int x = pq.top().second;
        int t = (-1) * pq.top().first;
        pq.pop();

        int nx1 = x + 1, nt1 = t + 1;
        int nx2 = x - 1, nt2 = t + 1;
        int nx3 = 2 * x, nt3 = t;

        if (nx1 <= MAX && dist[nx1] > nt1) {
            dist[nx1] = nt1;
            pq.push({ -1 * nt1, nx1 });
        }

        if (nx2 >= 0 && dist[nx2] > nt2) {
            dist[nx2] = nt2;
            pq.push({ -1 * nt2, nx2 });
        }

        if (nx3 <= MAX && dist[nx3] > nt3) {
            dist[nx3] = nt3;
            pq.push({ -1 * nt3, nx3 });
        }
    }

    cout << dist[K] << "\n";

    return 0;
}