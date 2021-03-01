#include <iostream>

using namespace std;

int main()
{
    int ans_sum = -1, ans_index = -1;
    for (int i = 1;  i <= 5; i++)
    {
        int sum = 0;
        for (int j = 1; j <= 4; j++)
        {
            int a;
            cin >> a;
            sum += a;
        }
        if (sum > ans_sum)
        {
            ans_index = i;
            ans_sum = sum;
        }
    }
    cout << ans_index << " " << ans_sum << endl;
    return 0;
}