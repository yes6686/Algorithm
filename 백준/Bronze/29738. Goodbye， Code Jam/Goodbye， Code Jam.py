def solution(n):
    if  n <= 25:
        return 'World Finals'
    elif n <= 1000:
        return 'Round 3'
    elif n <= 4500:
        return 'Round 2'
    else:
        return 'Round 1'
 
if __name__ == '__main__':
    cnt = 1
    t = int(input())
    for i in range(t):
        n = int(input())
        result = solution(n)
        print(f'Case #{cnt}:',result)
        cnt += 1