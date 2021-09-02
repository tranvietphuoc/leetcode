#include <stdio.h>
#include <stdlib.h>

void horner(float *fcoeff, int n, float alpha) {
    // coeff is array of coefficient of polynomial
    // alpha is the part of x - alpha
    // n: the length of polynomial f
    float *gcoeff = (float *)malloc(sizeof(float) * n);
    gcoeff[0]     = fcoeff[0]; // b0 = a0
    for (int i = 1; i < n; i++) {
        gcoeff[i] = alpha * gcoeff[i - 1] + fcoeff[i];
    }

    printf("Before divise polynomial\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f*x^%d + ", fcoeff[i], n - 1 - i);
    }
    printf("\nAfter divise polynomial\n");
    printf("(x - %.2f)*(", alpha);
    for (int i = 0; i < n - 1; i++) {
        printf("%.2f*x^%d + ", gcoeff[i], n - 2 - i);
    }
    printf(")\n");

    free(gcoeff);
}

int main() {
    float fcoeff[] = {1, -2, -3, 7,
                      -2}; // simulate the array of coefficient of f polynomial
    float alpha    = 2;    // x - alpha
    int n          = 5;    // the length of fcoeff array
    horner(fcoeff, n, alpha);
}
