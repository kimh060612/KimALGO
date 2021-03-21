#include <iostream>

using namespace std;

int main()
{
    const int N = 7;
    int min = 987654321;
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 1) {
            sum += a;
            min = min > a ? a : min;
        }
    }
    if (sum == 0 || min == 987654321)cout << -1 << endl;
    else {
        cout << sum << endl << min << endl;
    }
    return 0;
}