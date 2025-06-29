#include<stdio.h>
#include<string.h>

int main() {
    char P[101];
    int K, isPrime, num, key = 1000001;
    scanf("%s %d", P, &K);
    for(int i=2; i<=K; i++) {
        isPrime = 1;
        for(int j=2; j*j<=i; j++) if(i%j == 0) { isPrime = 0; break; }
        if(!isPrime) continue;
        num = 0;
        for(int j=0; j<strlen(P); j++) num = (num*10 + P[j] - '0') % i;
        if(!num) { key = i; break; }
    }
    if(key < K) printf("BAD %d", key);
    else printf("GOOD");
}