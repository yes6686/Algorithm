n, m = map(int,input().split())
if m <= 2:
    print("NEWBIE!")
elif n < m:
    print("TLE!")
else:
    print("OLDBIE!")