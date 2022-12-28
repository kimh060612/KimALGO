#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t --)
    {
        int a, b;
        cin >> a >> b;
        int k = 1;
        for (int i = 1; i <= b; i++) k = (k * a) % 10;
        int ans = k % 10 != 0 ? k % 10 : 10;
        cout << ans << endl;
    }
    return 0;
}