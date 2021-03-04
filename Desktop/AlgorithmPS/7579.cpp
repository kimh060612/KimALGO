#include <stdio.h>
#define MAX(x, y) x>y?x:y

int memory[101], cost[101];
int dp[100 * 100 + 1];

int main() {

	int N, M;

	// 입력
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", &memory[i]);
	for (int i = 1; i <= N; i++)
		scanf("%d", &cost[i]);

	// dp 배열 채우기
	for (int i = 1; i <= N; i++)
		for (int j = 100 * 100; j >= 0; j--) {
			if (j < cost[i])
				break;
			dp[j] = MAX(dp[j], dp[j - cost[i]] + memory[i]);
		}

	// 출력
	for (int i = 0; i <= 100 * 100; i++)
		if (dp[i] >= M){
			printf("%d", i);
			break;
		}
        
	return 0;
}
