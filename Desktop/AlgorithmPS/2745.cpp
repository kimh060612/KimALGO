#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int b;
    string n;
    cin >> n >> b;
    int ans = 0, temp = 1;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        if (65 <= n[i] && n[i] <= 65 + 25)
        {
            int k = n[i] - 65 + 10;
            ans += k * temp;
        }
        else if (48 <= n[i] && n[i] <= 48 + 9)
        {
            ans += (n[i] - 48) * temp;
        }
        temp *= b;
    }
    cout << ans << endl;
    return 0;
}