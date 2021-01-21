#include <iostream>
#include <queue>
#define MAX 100000

using namespace std;

int A[MAX + 1], check[MAX + 1];
int N, K;

int main()
{
    cin >> N >> K;
    if (N == K)
    {
        cout << 0 << endl << 1 << endl;
        exit(0);
    }
    queue<pair<int, int>> Q;
    Q.push({N, 0});
    check[N] = 1;
    int ans = 0, cnt = 0;
    while (!Q.empty())
    {
        int X = Q.front().first;
        int sec = Q.front().second;
        Q.pop();
        check[X] = 1;    

        if (ans != 0 && ans < sec) break;
        if (ans == sec && X == K)cnt++;
        if (ans == 0 && X == K)
        {
            ans = sec;
            cnt++;
        }

        if (X + 1 <= MAX && !check[X + 1]) Q.push({X +1, sec + 1});
        if (X - 1 >= 0 && !check[X - 1]) Q.push({X - 1, sec + 1});
        if (2*X <= MAX && !check[2*X]) Q.push({2*X, sec + 1});
    }
    
    
    cout << ans << endl << cnt << endl;

    return 0;
}