#include <iostream>

using namespace std;

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int ans1 = x > y ? y : x;
    int ans2 = w - x > h - y ? h - y : w - x;
    cout << (ans1 > ans2 ? ans2 : ans1) << endl;
    return 0;
}