#include <iostream>

using namespace std;

int main()
{
    int s, t, d;
    cin >> s >> t >> d;
    int k = d / (2 * s);
    cout << t * k << endl;
    return 0;
}