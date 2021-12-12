#include <iostream>

using namespace std;

int F(int x)
{
    if (x == 0) return 2;
    if(x <= 5) return x; 
    else return 10 - x;
}

int main()
{
    int n;
    cin >> n;
    cout << F(n % 8) << endl;
    return 0;
}