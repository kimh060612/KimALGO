#include <cstdio>

using namespace std;

int main() {

    int n, m, k, limit, x = 1;
    scanf("%d %d %d", &n, &m, &k);

    limit = n + m - k;
    
    while(1) {
        int tempn = x * 2;
        int tempm = x;
        if (tempn + tempm > limit || tempn > n || tempm > m) break;
        x++;
    }

    printf("%d\n", --x);

    return 0;
}