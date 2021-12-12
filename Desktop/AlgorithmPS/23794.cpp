#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << "@";
    for (int i = 1; i <= n; i++) cout << "@";
    cout << "@" << endl;
    
    for (int i = 1; i <= n; i++)
    {
        cout << "@";
        for (int i = 1; i <= n; i++) cout << " ";
        cout << "@" << endl;
    }

    cout << "@";
    for (int i = 1; i <= n; i++) cout << "@";
    cout << "@";

    return 0;
}