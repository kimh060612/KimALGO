#include <iostream>

using namespace std;

struct Coord
{
    int x, y;
};

Coord A[3];

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int temp = x1*y2+x2*y3+x3*y1;
    temp = temp - y1*x2-y2*x3-y3*x1;
    if (temp > 0) {
        return 1;
    } else if (temp < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        cin >> A[i].x >> A[i].y;
    }

    cout << ccw(A[0].x, A[0].y, A[1].x, A[1].y, A[2].x, A[2].y) << endl;

    return 0;
}