N = int(input())

if N >= -32768 and N <= 32767:
    print("short")
elif N >= -2147483648 and N <= 2147483647:
    print("int")
else:
    print("long long")