#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        double avg = 0.;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int a;
            double b;
            cin >> a >> b;
            sum += a;
            avg += a * b;
        }
        avg /= (double)sum;
        cout.precision(2);
        cout << sum << " " <<  avg << endl;
    }
    return 0;
}