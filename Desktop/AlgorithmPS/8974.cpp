#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int cnt = 1, sum = 0;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (cnt >= a && cnt <= b) sum += i;
            cnt ++;
        }
    }
    cout << sum << endl;
    return 0;
}