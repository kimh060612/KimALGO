A = input().split(' ')
N, M = int(A[0]), int(A[1])
nCr = []
for i in range(101):
    A = [0] * 101
    nCr.append(A)

for i in range(101):
    nCr[i][0] = 1
    nCr[i][i] = 1

for i in range(1, 101):
    for j in range(1, 101):
        nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j]
print(int(nCr[N][M])) 