dp = [0 for i in range(1001)]
dp[1] = 1
dp[2] = 2
for i in range(3,1001,1):
  dp[i] = dp[i - 1] + dp[i - 2]


while True:
    input_ = input().split(' ')
    a, b = int(input_[0]), int(input_[1])
    if a == b and b == 0:
        break
    cnt = 0
    for i in range(1,1001,1):
        if a <= dp[i] and dp[i] <= b:
            cnt+=1
    print(cnt)