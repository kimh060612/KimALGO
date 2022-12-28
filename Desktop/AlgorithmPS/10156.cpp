#include <iostream>

using namespace std;

int main()
{
    int N, K, M;
    cin >> N >> K >> M;
    int ans = (N * K - M) > 0 ? (N * K - M) : 0;
    cout << ans << endl; //.
    return 0;
}
