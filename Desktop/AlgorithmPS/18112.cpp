#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int s, t, S, T;
int check[2048];

int numBits(int n)
{
    int k = 0;
    while (n > 0)
    {
        n /= 2;
        k ++;
    }
    return k;
}

int I2B(int n)
{
    int ans = 0;
    int k = 0;
    while (n > 0)
    {
        int tmp = n % 10;
        if (tmp == 1)ans += 1 << k;
        n /= 10;
        k++;
    }
    return ans;
}

int main()
{   
    cin >> s >> t;

    S = I2B(s);
    T = I2B(t);
    
    int ans = 0;
    queue<pair<int, int>> Q;
    Q.push({S, 0});
    check[S] = 1;
    while (!Q.empty())
    {
        int X = Q.front().first;
        int l = Q.front().second;
        Q.pop();

        if (X == T) {
            ans = l;
            break;
        }

        if (X >= 1 && !check[X - 1])
        {
            check[X - 1] = 1;
            Q.push({X - 1, l + 1});
        }

        if (!check[X + 1])
        {
            check[X + 1] = 1;
            Q.push({X + 1, l + 1});
        }

        int b = numBits(X);
        for (int i = 0; i < b - 1; i++)
        {
            int o = 1 << i;
            if (X & o) {
                int nx = X - o;
                if (!check[nx]) {
                    check[nx] = 1;
                    Q.push({nx, l + 1});
                }
            }
            else {
                int nx = X + o;
                if (!check[nx]) {
                    check[nx] = 1;
                    Q.push({nx, l + 1});
                }
            }
        }
    }

    std::cout << ans << endl;
    return 0;
}