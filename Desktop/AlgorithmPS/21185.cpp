#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n % 2 == 1) cout << "Either" << endl;
    else {
        n /= 2;
        if (n % 2 == 1) cout << "Odd" << endl;
        else cout << "Even" << endl;
    }
    return 0;
}