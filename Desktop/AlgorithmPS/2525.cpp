#include <iostream>

using namespace std;

int main()
{
    int h, m, t;
    cin >> h >> m;
    cin >> t;
    cout << (h + (m + t) / 60)% 24 << " " << (m + t) % 60 << endl;
    return 0;
}