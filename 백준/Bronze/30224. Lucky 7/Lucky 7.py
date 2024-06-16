n = int(input())
c_7 = '7' in str(n)
if not c_7 and not n % 7 == 0:
  print(0)
elif not c_7 and n % 7 == 0:
  print(1)
elif c_7 and not n % 7 == 0:
  print(2)
else:
  print(3)
