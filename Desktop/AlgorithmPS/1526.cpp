#include <iostream>

using namespace std;

bool check(int num)
{
    while(num)
    {
        if(num%10 != 4 && num %10 != 7) return false;
        num/=10;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for(int i=n;i>=1;i--)
    {
        if(check(i))
        {
            cout << i;
            break;
        }
    }
    return 0;
}