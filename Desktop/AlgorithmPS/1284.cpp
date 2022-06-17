#include <iostream>
#include <string>

using namespace std;

int main()
{
    while (1) 
    {
        string s;
        cin >> s;
        if (s == "0") break;
        int ans = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1') ans += 2;
            else if (s[i] == '0') ans += 4;
            else ans += 3;
            ans += 1;
        }
        cout << ans << endl;
    }
    return 0;
}