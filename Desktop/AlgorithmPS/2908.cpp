#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    string a_ = "", b_ = "";
    for (int i = 0; i < a.size(); i++) a_ += a[a.size() - 1 - i];
    for (int i = 0; i < b.size(); i++) b_ += b[b.size() - 1 - i];
    string ans = stoi(a_) > stoi(b_) ? a_ : b_;
    cout << ans << endl; 
    return 0;
}