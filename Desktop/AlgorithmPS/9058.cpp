#include <iostream>

using namespace std;

int N, T;

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++) 
    {
        int sum = 0;
        cin >> N;
        for (int i = 1; i <= N; i++) 
        {
            int a;
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
    }
    return 0;
}