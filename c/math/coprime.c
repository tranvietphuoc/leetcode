#include <stdio.h>

// coprime or relatively prime if the gcd is 1

int gcd(int u, int v) {
    // find greatest common divison (gcd)
    int t;
    while (u > 0) {
        if (u < v) {
            t = u;
            u = v;
            v = t;
        }
        u -= v;
    }
    return v;
}

int coprime(int u, int v) {
    if (gcd(u, v) == 1) {
        return 1;
    }
    return 0;
}

int main() {
    if (coprime(6, 27)) {
        printf("%d and %d is coprime", 6, 27);
    } else {
        printf("nope");
    }
}
