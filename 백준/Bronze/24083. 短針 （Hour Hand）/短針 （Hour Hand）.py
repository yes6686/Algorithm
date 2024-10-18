a = int(input())
b = int(input())
hour = (a+b) % 12
print(hour if hour != 0 else 12)