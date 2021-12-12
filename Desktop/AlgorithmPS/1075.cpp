#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, f;
    cin >> n >> f;
    for(int i = 0; i < 10; i++)
    {
        char s = i + '0';
        for(int j = 0; j < 10; j++)
        {
            char e = j + '0';
            string res = to_string(n);
            int N = res.length();
            res[N - 1] = e;
            res[N - 2] = s;
            int k = stoi(res);
            if (k % f == 0){
                cout << s << e << endl;
                return 0;
            }
        }
    }
    return 0;
}