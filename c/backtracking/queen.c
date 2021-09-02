#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int chess_board[20], count;

int placeholder(int row, int col) {
    int count;
    for (count = 1; count <= row - 1; count++) {
        if (chess_board[count] == col) {
            return 0;
        } else {
            if (abs(chess_board[row] - col) == abs(count - row)) {
                return 0;
            }
        }
    }
    return 1;
}

void display(int num) {
    int m, n;
    printf("\nPossible Solution %d:\n", ++count);
    for (m = 1; m <= num; m++) {
        printf("\t[%d]", m);
        for (n = 1; n <= num; n++) {
            if (chess_board[m] == n) {
                printf("\tQ");
            } else {
                printf("\t*");
            }
        }
    }
}

void nqueen_function(int row, int num) {
    for (int col = 1; col <= num; col++) {
        if (placeholder(row, col)) {
            chess_board[row] = col;
            if (row == num) {
                display(num);
            } else {
                nqueen_function(row + 1, num);
            }
        }
    }
}

int main() {
    int num;
    printf("\nEnter number of Queens\n");
    scanf("%d", &num);
    if (num <= 3) {
        printf("\nNumber should be greater than 3 form a Matrix\n");
    } else {
        nqueen_function(1, num);
    }
    printf("\n\n");
    return 0;
}
