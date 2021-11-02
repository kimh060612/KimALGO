#include <iostream>

using namespace std;

int main()
{
    int r, c, n;
    cin >> r >> c >> n;
    long long h = r % n != 0 ? int(r / n) + 1 : r / n;
    long long w = c % n != 0 ? int(c / n) + 1 : c / n;
    cout << (long long)h * w << endl;
}