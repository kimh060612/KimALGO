#include <cstdio>
int a, b, c, x, y, sum, min, t;
int main() {
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
	t = c * 2 * (x > y ? x : y);
	
	if (a + b > c * 2) {	
		min = x > y ? y : x;	
		sum = c * 2 * min;	
		x -= min; y -= min;	
	}
	sum += a * x + b * y;	
	if (t < sum)
		sum = t;
	printf("%d", sum);
	return 0;
}