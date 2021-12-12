#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n % 2 == 0){
        n /= 2;
        if (n % 2 == 1) cout << 1 << endl;
        else cout << 2 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}