dp = [0] * 200

dp[1] = 1
dp[2] = 1
dp[3] = 1
for i in range(4, 117):
    dp[i] = dp[i - 1] + dp[i - 3]

A = int(input())
print(dp[A])
