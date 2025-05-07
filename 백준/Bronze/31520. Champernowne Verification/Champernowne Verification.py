def sol(s):
    start = 1
    chk = ''
    while len(s) != len(chk):
        chk += str(start)
        if s[:len(chk)] != chk:
            return -1
        start += 1
    start -= 1
    if chk == s:
        return start
    else:
        return -1
 
 
if __name__ == '__main__':
    s = input()
    print(sol(s))
 