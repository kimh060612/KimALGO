
N = int(input())
cnt_0 = 0
cnt_1 = 1

for i in range(N-1):
    if i % 2:
        tmp_cnt_0 = cnt_0 + cnt_1 - 1
    else:
        tmp_cnt_0 = cnt_0 + cnt_1
    tmp_cnt_1 = cnt_0 + cnt_1
    cnt_0 = tmp_cnt_0
    cnt_1 = tmp_cnt_1
print(cnt_0)


"""// #include <iostream>

// using namespace std;

// long long DP[1001];

// int main()
// {
//     int N;
//     cin >> N;
//     DP[1] = 0;
//     for (int i = 2; i <= N; i++)
//     {
//         if (i % 2 == 0)DP[i] = 2 * DP[i - 1] + 1;
//         else DP[i] = 2 * DP[i - 1] - 1;
//     }
//     cout << DP[N] << endl;
//     return 0;
// }"""

