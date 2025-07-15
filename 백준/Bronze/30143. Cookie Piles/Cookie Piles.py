def total_cookies(N, A, D):
    return N * A + D * (N * (N - 1)) // 2
 
def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
 
    T = int(data[0])
    results = []
 
    for i in range(1, T + 1):
        N, A, D = map(int, data[i].split())
        result = total_cookies(N, A, D)
        results.append(result)
 
    for result in results:
        print(result)
 
if __name__ == "__main__":
    main()