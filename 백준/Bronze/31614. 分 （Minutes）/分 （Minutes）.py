def sol(h, m):
    return h * 60 + m
 
if __name__ == '__main__' :
    h = int(input())
    m = int(input())
    print(sol(h, m))