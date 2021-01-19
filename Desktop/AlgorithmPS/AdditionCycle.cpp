#include <iostream>

using namespace std;

int main()
{
    int N, cnt = 0;
    cin >> N;
    int new_num, N_save = N;
    int ten, one;
    while (1)
    {
        if (N/10 == 0)ten = 0;
        else ten = (N/10)%10;
        one = N % 10;
        new_num = ten + one;
        cnt ++;
        N = (one * 10) + (new_num%10);
        if (N == N_save)break;
    }
    cout << cnt << endl;
    return 0;
}