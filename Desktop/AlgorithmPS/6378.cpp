#include <iostream>
#include <string>

using namespace std;

long long summation(string s)
{
    long long sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum += (s[i] - 48);
    }
    return sum;
}

int main()
{
    while (1)
    {
        string s;
        cin >> s;
        if (s == "0") break;
        long long tmp = summation(s);
        while (tmp > 9)
        {
            tmp = summation(to_string(tmp));
        }
        cout << tmp << endl;
    }
    return 0;
}