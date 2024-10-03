#include <stdio.h>
#include "malloc.h"

struct Person {
    int age;
};

int main() {
    struct Person *p = malloc(sizeof(struct Person));
    p->age = 10;
    printf("%d\n", p->age);
    p = realloc(p, 2 * sizeof(struct Person));
    p->age=20000;
    printf("%d\n", p->age);
    free(p);
    return 0;
}