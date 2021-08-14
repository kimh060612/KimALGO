#include <iostream>

using namespace std;
typedef long long ll;

ll CCW(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll v1x = x2 - x1;
    ll v1y = y2 - y1;
    ll v2x = x3 - x2;
    ll v2y = y3 - y2;
    long long k = (long long)v1x * v2y - v1y * v2x;
    if (k > 0) return 1;
    else if (k < 0) return -1;
    else return 0;
}

void swap(ll &a, ll &b)
{
    ll tmp = b;
    b = a;
    a = tmp;
}

int main()
{

    ll x1, y1, x2, y2;
    ll x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    ll k1 = CCW(x1, y1, x2, y2, x3, y3);
    ll k2 = CCW(x1, y1, x2, y2, x4, y4);

    ll k3 = CCW(x3, y3, x4, y4, x1, y1);
    ll k4 = CCW(x3, y3, x4, y4, x2, y2);

    if (k1 * k2 <= 0 && k3 * k4 <= 0) {
        if (k1 * k2 == 0 && k3 * k4 == 0) {
            if (x2 < x1) {
                swap(y2, y1);
                swap(x2, x1);
            }
            if (x2 == x1 && y2 < y1) {
                swap(y2, y1);
                swap(x2, x1);
            }
            if (x4 < x3) {
                swap(y3, y4);
                swap(x3, x4);
            }
            if (x3 == x4 && y4 < y3) {
                swap(y3, y4);
                swap(x3, x4);
            }
            
            if ((x1 < x4 || (x1 == x4 && y1 <= y4)) && (x3 < x2 || (x2 == x3 && y3 <= y2))) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else cout << 1 << endl;
    }
    else cout << 0 << endl;

    return 0;
}