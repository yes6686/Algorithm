n = [] # 리스트로 선언언

while True : 
    sum = 0
    n = input()
    if n == '0' : # n값이 0일 때 무한반복 종료
        break
    sum += len(n) + 1 # 호수판 경계 여백 더하기 
    
    for i in range(len(n)) : 
        if n[i] == '1' : # n값이 1일 때 2 더하기
            sum += 2    
        elif n[i] == '0' : # n값이 0일 때 4 더하기
            sum += 4
        else :             # n값이 다른 숫자자일 때
            sum += 3
    print(sum) 