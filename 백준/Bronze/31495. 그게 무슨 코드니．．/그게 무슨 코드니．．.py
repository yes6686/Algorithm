code = input()

if code[0] == code[-1] == '"' and len(code[1:-1]) > 0:
    print(code[1:-1])
else:
    print("CE")