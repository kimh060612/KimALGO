A = input()
if len(A) == 2:
    print(int(A[0]) + int(A[1]))
elif len(A) == 3:
    a, b, c = int(A[0]), int(A[1]), int(A[2])
    if b == 0:
        print(10 + c)
    else :
        print(a + 10)
else :
    print(20)