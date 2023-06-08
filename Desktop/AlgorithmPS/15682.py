from decimal import Decimal, getcontext

getcontext().prec = 100
MAX = Decimal('10000000')
EPS = Decimal('1e-20')
p = 20

def equation(a, b, c, d, x):
    return a * (x ** 3) + b * (x ** 2) + c * x + d

def bisection(xs: Decimal, xe: Decimal, a: Decimal, b: Decimal, c: Decimal, d: Decimal):
    m = (xs + xe) / Decimal(2)
    while round((xe - xs).__abs__(), p) > 10 ** (-p):
        fs = equation(a, b, c, d, xs)
        fm = equation(a, b, c, d, m)
        if fs * fm > 0:
            xs = m
        else:
            xe = m
        m = (xs + xe) / Decimal(2)
    return xs

def solve(a: Decimal, b: Decimal, c: Decimal, d: Decimal):
    D = (b ** 2) - Decimal(3) * a * c
    if D > 0:
        s1 = (-b + D.sqrt()) / (Decimal(3) * a)
        s2 = (-b - D.sqrt()) / (Decimal(3) * a)
        if s2 > s1:
            s1, s2 = s2, s1
        if abs(round(equation(a, b, c, d, s1), p)) < EPS:
            return [ bisection(-MAX, s2, a, b, c, d), s1 ]
        if abs(round(equation(a, b, c, d, s2), p)) < EPS:
            return [ s2, bisection(s1, MAX, a, b, c, d) ]
        if round(equation(a, b, c, d, s1) * equation(a, b, c, d, s2), p) > 0:
            return [ bisection(-MAX, MAX, a, b, c, d) ]
        return [ 
            bisection(-MAX, s2, a, b, c, d),
            bisection(s2, s1, a, b, c, d),
            bisection(s1, MAX, a, b, c, d)
        ]
    else:
        return [ bisection(-MAX, MAX, a, b, c, d) ]

N = int(input())
while N:
    data = input().split(' ')
    A, B, C, D = Decimal(data[0]), Decimal(data[1]), Decimal(data[2]), Decimal(data[3])
    ans = solve(A, B, C, D)
    ans.sort()
    ans=['{:.20f}'.format(x) for x in ans]
    for a in ans:
        print(a, end=' ')
    print()
    N -= 1