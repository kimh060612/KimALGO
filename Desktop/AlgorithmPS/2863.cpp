#include <iostream>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    double one = a / (double)c + b / (double)d;
    double two = c / (double)d + a / (double)b;
    double three = d / (double)b + c / (double)a;
    double four = b / (double)a + d / (double)c;
    double ans = max(max(one, two), max(three, four));
    if (ans == one) cout << 0 << endl;
    else if (ans == two) cout << 1 << endl;
    else if (ans == three) cout << 2 << endl;
    else cout << 3 << endl;
    return 0;    
}