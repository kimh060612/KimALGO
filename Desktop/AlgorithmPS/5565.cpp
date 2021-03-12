#include <iostream>

using namespace std;

int main()
{
    int total;
    cin >> total;
    int sum = 0;
    for (int i = 1; i <= 9; i++)
    {
        int a;
        cin >> a;
        sum += a;
    }
    cout << total - sum << endl;
    return 0;
}