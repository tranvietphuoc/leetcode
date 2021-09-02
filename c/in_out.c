#include <stdio.h>

int main() {
    char *name;
    printf("Type your name?");
    scanf("%s", name);
    printf("Your name is: %s\n, %d", name, sizeof(name));
    return 0;
}
