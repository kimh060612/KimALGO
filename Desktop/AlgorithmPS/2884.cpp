#include <iostream>

using namespace std;

int main()
{
    int H, M;
    cin >> H >> M;
    int K = H * 60 + M;
    int ans = K >= 45 ? K - 45 : K - 45 + 24 * 60;
    cout << ans / 60 << " " << ans % 60 << endl;
    return 0;
}