#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        cout << s[0] << s[s.length() - 1] << endl;
    }
    return 0;
}