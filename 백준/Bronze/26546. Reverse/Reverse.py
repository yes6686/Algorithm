for _ in range(int(input())) :
    string, i, j = input().split()
    print(string[:int(i)] + string[int(j):])