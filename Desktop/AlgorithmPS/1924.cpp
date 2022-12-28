#include <iostream>
#include <string>

using namespace std;

int MONTH[14] = {0, 31, 28, 31, 30, 31, 30, 31, 31 ,30, 31, 30, 31};
string ANS[9] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main()
{
    int x, y;
    cin >> x >> y;

    int days = 0;
    for (int i = 1; i < x; i++)
    {
        days += MONTH[i];
    }
    days += y;

    cout << ANS[days % 7] << endl;


    return 0;
}