#include <stdio.h>
#include <stdlib.h>

// calculate the combination k of n
// Comb(n, k) = 1 if k == 0 or k == n
// else Comb(n, k) = Comb(n - 1, k - 1) + Comb(n - 1, k)
// time complexity = O(2**n)

int Comb(int n, int k) {
    // create a 2-d array to hold the calculated combination
    // init an array
    /* int **C = (int**)malloc(sizeof(int*) * n); */
    /* if C { */
    /*     for(int k = 0; k < n; k++) { */
    /*         *C = (int*)malloc(sizeof(int)*n); */
    /*     } */
    /* } */
    int C[1000][1000];
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

// time complexity of dynamic programming is O(n**2)

int main() {
    printf("Test combination function:\n");
    printf("%d", Comb(4, 2));
}
