#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < 26; i++)
    {
        int index = -1;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == i + 97) {
                index = j;
                break;
            }
        }
        cout << index << " ";
    }
    cout << endl;

    return 0;
}