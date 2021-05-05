#include <stdio.h>
#include <math.h>

/* // normal recursive */
/* void solveCollatz(int x) { */
/* 	if(x == 1) { */
/* 		printf("%d", x); */
/* 	} else { */
/* 		if(x % 2 == 0) { */
/* 			solveCollatz(x / 2); */
/* 			printf(" * 2"); */
/* 		} else { */
/* 			solveCollatz(x * 3 +1); */
/* 			printf(" div 3"); */
/* 		} */
/* 	} */
/* } */

//supported recursive

void solveCollatz(int x) {
	if(x == 1) {
		printf("%d", x);
	} else {
		if(x % 2 == 0) {
			solveCollatzEven(x);
		} else {
			solveCollatzOdd(x);
		}
	}
	return;
}

void solveCollatzOdd(int x) {
	solveCollatz((int)((x * 3) + 1));
	printf(" div 3");
	return;
}

void solveCollatzEven(int x) {
	solveCollatz((int)(x / 2));
	printf(" * 2");
	return;
}



int main() {
	solveCollatz(23);
	printf("\n");
	return 0;
}
