I = input()
a, b = int(I.split(' ')[0]), int(I.split(' ')[1])
c, d = a//b, a%b
if a != 0 and d < 0:
    c, d = c+1, d-b
print(c)
print(d)
