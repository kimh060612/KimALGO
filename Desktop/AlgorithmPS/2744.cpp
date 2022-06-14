#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (65 <= s[i] && s[i] <= 65 + 26) cout << (char)(s[i] + 32);
        else cout << (char)(s[i] - 32);
    }
    cout << endl;
    return 0;
}