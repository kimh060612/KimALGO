#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char a = (n + 8) % 12 + 65;
    int b = (n + 6) % 10;
    cout << a << b << endl;
    return 0;
}