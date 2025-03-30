#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	
	int oh = 1;
	int od = 1;
	while (n--) {
		oh += a;
		od += b;
		if (oh < od) {
			int temp = oh;
			oh = od;
			od = temp;
		}
		else if (oh == od) {
			od -= 1;
		}
	}

	printf("%d %d\n", oh, od);

	return 0;
}