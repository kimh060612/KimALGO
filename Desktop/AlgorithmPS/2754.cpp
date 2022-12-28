#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    cout.precision(1);
    cout << fixed;
    if (s == "A+") cout << 4.3 << endl;
    else if (s == "A0") cout << 4.0 << endl;
    else if (s == "A-") cout << 3.7 << endl;
    else if (s == "B+") cout << 3.3 << endl;
    else if (s == "B0") cout << 3.0 << endl;
    else if (s == "B-") cout << 2.7 << endl;
    else if (s == "C+") cout << 2.3 << endl;
    else if (s == "C0") cout << 2.0 << endl;
    else if (s == "C-") cout << 1.7 << endl;
    else if (s == "D+") cout << 1.3 << endl;
    else if (s == "D0") cout << 1.0 << endl;
    else if (s == "D-") cout << 0.7 << endl;
    else cout << 0.0 << endl;
    return 0;
}