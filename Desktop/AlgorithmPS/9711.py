DP = [0 for _ in range(10002)]
DP[1] = 1
DP[2] = 1
for i in range(3, 10001):
    DP[i] = DP[i - 1] + DP[i - 2]

t = int(input())
for t_ in range(t):
    A = input().split()
    p, q = int(A[0]), int(A[1])
    print("Case #{}: {}".format(t_ + 1, DP[p] % q))