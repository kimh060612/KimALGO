#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    char o;
    cin >> a >> o >> b;

    if (o == '*') {
        cout << 1;
        for (int i = 1; i <= a.size() + b.size() - 2; i++) cout << 0;
        cout << endl;
    } else {
        if (a.size() != b.size()) {
            string k, l;
            k = a.size() > b.size() ? a : b;
            l = a.size() < b.size() ? a : b;
            for (int i = 0, j = 0; i < k.size(); i++)
            {
                if (k.size() - i <= l.size()) { 
                    cout << l[j]; 
                    j++;
                } 
                else cout << k[i];
            }
            cout << endl;
        } else {
            cout << 2;
            for (int i = 1; i < a.size(); i++) cout << 0;
            cout << endl;
        }
    }

    return 0;
}