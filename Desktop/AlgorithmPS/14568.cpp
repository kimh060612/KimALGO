#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s = 0;
    for (int i = 2; i < n; i += 2)
    {
        s += (n - i - 2) / 2;
    }
    cout << s << endl;
    return 0;
}