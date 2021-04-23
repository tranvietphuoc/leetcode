import re
for _ in range(int(input().strip())):
    s = input().strip()
    try:
        re.compile(s)
        print("True")
    except re.error:
        print("False")
