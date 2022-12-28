#include <iostream>

using namespace std;

int main()
{
    while (1) 
    {
        long long a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        int _min = a < b ? a : b;
        int _max = a > b ? a : b;
        int c = 0, ans = 0;
        while (_max)
        {
            int k = _min % 10;
            int l = _max % 10;
            c = (k + l + c) / 10;
            if (c != 0) ans ++;
            _min /= 10;
            _max /= 10;
        }

        cout << ans << endl;
    }
    return 0;
}