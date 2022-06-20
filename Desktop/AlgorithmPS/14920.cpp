#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
    ll c;
    cin >> c;
    int n = 1;
    while (1) 
    {
        if (c == 1) break;
        if (c % 2 == 0) c = c / 2;
        else c = 3 * c + 1;
        n++;
    }
    cout << n << endl;
    return 0;
}