#include <stdio.h>
#include <stdlib.h>

const int maxn = 8;

int dd[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dc[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int a[12][12];

int m, n, x, y, s, stop, flag, flag1;

void init() {
    for (int i = 0; i < m + 4; i++)
        for (int j = 0; j < n + 4; j++)
            a[i][j] = -1;
    for (int i = 2; i < m + 2; i++)
        for (int j = 2; j < n + 2; j++)
            a[i][j] = 0;

    y++;
    x++;
    s       = 1;
    a[y][x] = s;
    stop    = 0;
    flag    = 0;
}

void print_a() {
    for (int i = 2; i < m + 2; i++) {
        for (int j = 2; j < n + 2; j++) {
            if (a[i][j] < 10)
                printf("%d ", a[i][j]);
            else
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int movel(int s, int *flag) {
    int d, c;
    for (int j = 0, flag1 = 0; j < 8; j++) {
        d = y + dd[j];
        c = x + dc[j];
        if (a[d][c] == 0) {
            y       = d;
            x       = c;
            a[d][c] = s + 1;
            if (s + 1 == m * n) {
                print_a();
                stop++;
                exit(0);
            } else
                flag = movel(s + 1, &flag1);
            if (flag1 == 0) {
                a[d][c] = 0;
                y       = d - dd[j];
                x       = c - dc[j];
            }
        }
    }
    return *flag;
}

int main() {
    printf("Nhap kich thuoc co ban dong, cot la m, n <= 8: \n");
    scanf("%d", &m);
    scanf("%d", &n);
    printf("Nhap o xuat phat (dong, cot) = (y, x): \n");
    scanf("%d", &y);
    scanf("%d", &x);
    init();
    movel(s, &flag);
    if (stop == 0)
        printf("Vo nghiem\n");
    return 0;
}
