for _ in range(int(input())):
    n = int(input())  
    p1 = 0
    p2 = 0 
    for i in range(n):
        a, b = input().split()
        if a == b:
            continue
        elif  (a == 'P' and b == 'R') or (a == 'S' and b == 'P') or (a == 'R' and b == 'S'):
            p1+= 1
        else:
            p2+= 1
            
    if p1 < p2:
        print("Player 2")
    elif p1 > p2:
        print("Player 1")
    else:
        print("TIE")