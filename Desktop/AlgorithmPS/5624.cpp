#include <cstdio>
#include <algorithm>
#define mid 200000
using namespace std;
int a[5010], n, b[400040], res;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		int here = a[i];
		for (int j = 0; j < i; j++) {
			if (b[here - a[j] + mid]) {
				res++;
				break;
			}
		}
		for (int j = 0; j <= i; j++)
			b[here + a[j] + mid] = 1;
	}
	printf("%d\n", res);
	return 0;
}