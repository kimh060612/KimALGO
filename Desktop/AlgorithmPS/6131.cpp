#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= 500; i++)
    {
        for (int j = i + 1; j <= 500; j++)
        {
            if (i * i + n == j * j) ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}