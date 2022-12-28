#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        sum += (a - 1);
    }
    cout << sum + 1 << endl;
    return 0;
}