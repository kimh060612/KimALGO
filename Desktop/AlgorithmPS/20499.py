K = [int(x) for x in input().split('/')]
if (K[0] + K[2] < K[1]) or (K[1] == 0):
    print("hasu")
else :
    print("gosu")