#include <math.h>
#include <stdio.h>

// arithmetic progression is a sequence in form: an = a1 + (n-1) * d
// sum: n * (2 * a1 + (n - 1) * d)/2
//
int main() {
    int arithmetic_progression[] = {3,  5,  7,  9, 11,
                                    13, 15, 17, 19}; // 9 elements
    //
    // a2 = a1 + (n - 1) * d => d = 2
    int sum = 9 * (2 * 3 + (9 - 1) * 2) / 2;
    printf("sum of arithmetic progression is: %d", sum);
}
