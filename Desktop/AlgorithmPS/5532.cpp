#include <iostream>

using namespace std;

int main()
{
    int L, A, B, C , D;
    cin >> L >> A >> B >> C >> D;
    int a = A / C + ((A % C != 0) ? 1 : 0);
    int b = B / D + ((B % D != 0) ? 1 : 0);
    int ans = L - max(a, b);
    cout << ans << endl;
    return 0;
}