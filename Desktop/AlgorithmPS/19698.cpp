#include <iostream>

using namespace std;

int main()
{
    int N, W, H, L;
    cin >> N >> W >> H >> L;
    int K = (W / L) * (H / L);
    int ans = K > N ? N : K;
    cout << ans << endl;
    return 0;
}