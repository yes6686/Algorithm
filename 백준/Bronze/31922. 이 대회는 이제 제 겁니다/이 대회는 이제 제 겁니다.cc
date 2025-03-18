#include <iostream>
using namespace std;
int A, P, C;
int main()
{
    scanf("%d%d%d", &A, &P, &C);
    printf("%d", max(A + C, P));
}