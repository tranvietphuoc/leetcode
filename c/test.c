#include <stdio.h>

#define dprintf(expr) printf(#expr " = %g\n", expr)

int main() {
    double x = 10;
    double y = 5;
    dprintf(x/y);
}
