#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int c = 0;
    int nc = 0;
    while (N --)
    {
        int a;
        cin >> a;
        if (a)c ++;
        else nc ++;
    }
    if (nc > c) cout << "Junhee is not cute!" << endl;
    else cout <<  "Junhee is cute!" << endl;
    return 0;
}