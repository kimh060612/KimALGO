#include <iostream>

using namespace std;

int Mod[50];

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        int a;
        cin >> a;
        Mod[a % 42] = 1;
    }
    int ans = 0;
    for (int i = 0; i <= 41; i++) if (Mod[i]) ans ++;
    cout << ans << endl;
    return 0;
}