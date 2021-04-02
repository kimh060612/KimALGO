#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c) {
        cout << 10000 + a * 1000 << endl;
    } 
    else if (a == b || b == c || a == c) {
        int same;
        if (a == b) same = a;
        else if (b == c) same = b;
        if (a == c) same = a;
        cout << 1000 + same * 100 << endl;
    }
    else {
        int max = a;
        max = max < b ? b : max;
        max = max < c ? c : max;
        cout << max * 100 << endl;
    }
    return 0;
}