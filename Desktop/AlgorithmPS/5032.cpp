#include <iostream>

using namespace std;

int main() 
{
    int e, f, c,total=0;
    cin >> e >> f >> c;
    int empty_cola = e + f; 
    while (empty_cola >= c)
    {
        total += empty_cola / c; 
        empty_cola = empty_cola/c + empty_cola%c;
    }
    cout << total << '\n';
}
