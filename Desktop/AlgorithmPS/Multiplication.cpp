#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int ans3, ans4, ans5, ans6;
    ans3 = a * (b % 10);
    ans4 = a * ((b / 10) % 10);
    ans5 = a * ((b / 100) % 10);
    ans6 = a * b;

    cout << ans3 << endl;
    cout << ans4 << endl;
    cout << ans5 << endl;
    cout << ans6 << endl;

    return 0;
}