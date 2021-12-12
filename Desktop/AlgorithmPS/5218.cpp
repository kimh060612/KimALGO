#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s, e;
        cin >> s >> e;
        int N = s.length();
        cout << "Distances: ";
        for (int i = 0; i < N; i++)
        {
            int x = s[i];
            int y = e[i];
            if (y < x) cout << y + 26 - x << " ";
            else cout << y - x << " ";
        }
        cout << endl;
    }
    return 0;
}