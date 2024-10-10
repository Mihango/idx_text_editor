#include <stdio.h>
#include <stdbool.h>

int foo(int x, int y) {
    return x + y;
}

void display(int arr[10], bool (*predicate)(int)) {
    for(int i = 0; i < 10; i++) {
        if(predicate(arr[i])) {
            printf("%d ,", arr[i]);
        }
    }
    printf("=> END");
}

bool is_even(int x) {
    return x % 2 == 0;
}

int main(void) {
    int (*f)(int, int) = foo;
    int value = f(32, 40);
    printf("%d\n", value);

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(arr, is_even);

    return 0;
}