DP = [ [ 0 for _ in range(35) ] for _ in range(35) ]

for i in range(35):
    DP[i][i] = 1
    DP[i][0] = 1
    DP[i][1] = i
    
for i in range(2, 35):
    for j in range(1, i):
        DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j]

A = input()
n, k = int(A.split(' ')[0]), int(A.split(' ')[1])
print(DP[n - 1][k - 1])