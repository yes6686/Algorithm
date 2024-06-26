for _ in range(int(input())):
    prev = ''
    s = input()
    for i in range(len(s)):
        if prev != s[i]:
            print(s[i], end = "")
            prev = s[i]
    
    print()