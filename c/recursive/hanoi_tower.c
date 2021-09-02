#include <stdio.h>

void moveDisk(int n, int x, int y) {
    if (n == 1) {
        printf("Move 1 disk from column %d to column %d\n", x, y);
    } else {
        moveDisk(n - 1, x, 6 - x - y); // move n - 1 disks from x to medium
        moveDisk(1, x, y);             // move the largest disk from x to y
        moveDisk(n - 1, 6 - x - y, y); // move n - 1 disks from medium to y
    }
}

int main() { moveDisk(10, 1, 2); }
