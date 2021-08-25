#include <iostream>

using namespace std;

bool inRange(int x, int y) { return x > 0 && y > 0; }

int dx[2] = {1, -1};
int dy[2] = {-1, 1};

int main()
{
    int n, X = 1, Y = 1;
    cin >> n;
    int sw = 0;
    n --;
    while (n --) 
    {
        X += dx[sw % 2];
        Y += dy[sw % 2];
        if (!inRange(X, Y)) 
        {
            sw += 1;
            if (Y == 0) Y += 1;
            else if (X == 0) X += 1;
        }
    }
    cout << Y << "/" << X;
    return 0;
}