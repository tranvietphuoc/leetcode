
#!/bin/python3


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    n -= 1
    total = 0
    N = ceil(n // 3)  # the first value of the first A.P is 3, this A.P has N element
    M = ceil(n // 5)  # the first value of the first A.P is 5, this A.P has M element
    P = ceil(n // 15) # the first vallue of the fisrt A.P is 15, this A.P has P element
    # the form of sum of A.P: Sn = n * (2 * u1 + (n - 1) * d)/2
    # or: Sn = n * u1 + n * (n - 1) * d / 2
    # or: Sn = n * (u1 + un)/2
    # then:
    total = (N * (2 * 3 + (N - 1)* 3) + M * (2 * 5 + (M - 1) * 5) - P * (2 * 15 + (P - 1)*15))
    total >>= 1  # divide by 2, 
    # don't use division because python3 cast the
    # result into float, so, with a big numbers, the final total will be wrong
    print(total)
