#include <iostream>

using namespace std;

int main()
{
    int h, m, s, ts;
    cin >> h >> m >> s; 
    cin >> ts;

    int time = h * 3600 + m * 60 + s + ts;
    cout << (h + ( m + (s + ts) / 60 ) / 60) % 24 << " " << (m + (s + ts) / 60) % 60 << " " << (s + ts) % 60 << endl;  
    return 0;
}