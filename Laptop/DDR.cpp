#include <iostream>
#include <fstream>
#include <memory.h>
#include <math.h>
#define min(a, b) a > b ? b : a
#define INF 1000001

using namespace std;

//ifstream fin;
//ofstream fout;

int INPUT[INF];
int dp[5][5][100001];
int len;
 
int func(int l, int r, int i) {
    if (i == len)
        return 0;
 
    int& ref = dp[l][r][i];
    if (ref != -1)
        return ref;
 
    if (l == 0 && r == 0)
        return ref = func(INPUT[i], r, i + 1) + 2;
 
    if (l == INPUT[i])
        return ref = func(l, r, i + 1) + 1;
    else if (r == INPUT[i])
        return ref = func(l, r, i + 1) + 1;
 
    int left = 0;
    if (l == 0)
        left = func(INPUT[i], r, i + 1) + 2;
    else if (abs(l - INPUT[i]) == 2)
        left = func(INPUT[i], r, i + 1) + 4;
    else
        left = func(INPUT[i], r, i + 1) + 3;
 
    int right = 0;
    if (r == 0)
        right = func(l, INPUT[i], i + 1) + 2;
    else if (abs(r - INPUT[i]) == 2)
        right = func(l, INPUT[i], i + 1) + 4;
    else
        right = func(l, INPUT[i], i + 1) + 3;
 
    return ref = min(left, right);
}

int main()
{
    //fin.open("input.txt");
    //fout.open("output.txt");

    while (1)
    {
        int a;
        cin >> a;
        if (a == 0)break;
        INPUT[len++] = a;
    }

    memset(dp, -1, sizeof(dp));

    cout << func(0,0,0) << endl;

    //fin.close();
    //fout.close();
}
