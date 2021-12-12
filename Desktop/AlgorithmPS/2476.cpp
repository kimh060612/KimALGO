#include <iostream>

using namespace std;

int main()
{
    int n;
    int ans = -1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b && b == c) ans = max(10000 + a * 1000 , ans);
        else if (a == b || b == c || a == c) {
            if (a == b) ans = max(1000 + a * 100, ans);
            else if (b == c ) ans = max(1000 + b * 100, ans);
            else ans = max(1000 + c * 100, ans);
        }
        else {
            int m = max(a, max(b, c));
            ans = max(m * 100, ans); 
        }
    }
    cout << ans << endl;
    return 0;
}