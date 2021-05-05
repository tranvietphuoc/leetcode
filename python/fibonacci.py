def fibonacci_1(n):
    # use generator
    a, b = 0, 1
    while a < n:
        yield a
        a, b = b, a + b


def fibonacci_2(n):
    # use dynamic programming




if __name__ == '__main__':
    print(list(fibonacci(10)))
