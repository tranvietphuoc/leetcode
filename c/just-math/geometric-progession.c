#include <math.h>
#include <stdio.h>

// geometric progression is a sequence in form: a, a*r, a*r^2, a*r^3,...
// an = a1 * r^(n - 1)
// r = (an / a1)^(1/()n-1))
// sum: Sn+1 = a * (1 - r^(n + 1))/(1 - r)
//
int main() {
    int geometric[] = {1, 2, 4, 8, 16, 32, 64, 128}; // n=8
    double r        = pow(128 / 2, 1 / (8 - 1));
    printf("Sum of geometric progression is: %lf", r);
}
