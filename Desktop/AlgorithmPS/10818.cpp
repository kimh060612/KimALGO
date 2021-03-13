#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int min = 1000001, max = -1000001;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        min = min >= a ? a : min;
        max = max <= a ? a : max;
    }
    cout << min << " " << max;

    return 0;
}