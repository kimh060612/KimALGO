#include <iostream>

using namespace std;

int main()
{
    int train = 0;
    int ans = -1;
    for (int i = 1; i <= 10; i ++)
    {
        int a, b;
        cin >> a >> b;
        train += (b - a);
        ans = max(ans, train);
    }
    cout << ans << endl;
    return 0;
}