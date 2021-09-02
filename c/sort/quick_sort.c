#include <stdio.h>
#include <stdlib.h>

// implement quicksort
//
// swap two element
void swap(int *a, int *b) {
    int *t = a;
    a      = b;
    b      = t;
}

int Partition(int a[], int L, int R) {
    int i, j, p;
    i = L;
    j = R + 1;
    p = a[L];
    while (i < j) {
        i += 1;
        while ((i <= R) && (a[i] < p))
            i++;
        j--;
        while ((j >= L) && (a[j] > p))
            j--;
        swap(a[i], a[j]);
    }
    swap(a[i], a[j]);
    swap(a[j], a[L]);
    return j;
}

void quick_sort(int a[], int left, int right) {
    int p;
    if (left < right) {
        int pivot = Partition(a, left, right);
        if (left < pivot) {
            quick_sort(a, left, pivot - 1);
        }
        if (right > pivot) {
            quick_sort(a, pivot + 1, right);
        }
    }
}

int main() {
    int a[] = {30, 19, 24, 28, 41, 34, 15, 43, 20, 12, 36};
    printf("Array a before sort.");
    for (int i = 0; i <= sizeof(a) / sizeof(a[0]); i++) {
        printf("%d, ", a[i]);
    }
    quick_sort(a, 0, sizeof(a) / sizeof(a[0]));
    printf("Array a after sort.");
    for (int i = 0; i <= sizeof(a) / sizeof(int); i++) {
        printf("%d, ", a[i]);
    }

    return 0;
}
