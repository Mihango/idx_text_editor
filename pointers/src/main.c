#include <stdio.h>

int foo(int x, int y) {
    return x + y;
}

int main(void) {
    int (*f)(int, int) = foo;
    int value = f(32, 40);
    printf("%d\n", value);

    return 0;
}