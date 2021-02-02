#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int A, B, C;
int check[MAX][MAX];

void Step(int &X, int &Y)
{
    Y = Y - X;
    X = X * 2;   
}

int main()
{
    cin >> A >> B >> C;
    int D = A + B + C;

    if (D % 3)
    {
        cout << 0 << endl;
        return 0;
    }

    queue<pair<int, int>> Q;
    Q.push({A, B});
    check[A][B] = 1;

    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        int z = D - x - y;
        Q.pop();

        if (x == y && y == z)
        {
            cout << 1 << endl;
            return 0;
        }
        check[x][y] = 1;

        int nx[] = {x, x, y}, ny[] = {y, z, z};
        for (int i=0; i<3; i++) {
            int a = nx[i], b = ny[i];
            if (a < b) b -= a, a += a;
            else if (a > b) a -= b, b += b;
            else continue;
            int c = D-a-b;
            int X = min(min(a, b), c);
            int Y = max(max(a, b), c);
            if (!check[X][Y]) {
                Q.push(make_pair(X, Y));
                check[X][Y] = true;
            }
        }

    }

    cout << 0 << endl;
    return 0;
}