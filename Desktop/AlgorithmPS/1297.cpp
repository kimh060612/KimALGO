#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int D, H, W;
    cin >> D >> H >> W;
    cout << (int)(D / sqrt(H * H + W * W) * H)  << " " << (int)(D / sqrt(H * H + W * W) * W)  << endl;
    return 0;
}