#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a;
        cin >> a;
        if ((a[a.size() - 1] - '0') % 2 == 0) cout << "even" << endl;
        else cout << "odd" << endl;
    }
    return 0;
}