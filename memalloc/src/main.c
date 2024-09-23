#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked.h"

struct Person {
    char name[10];
    int age;
};

int main() {

    struct Person person;
    person.age = 20;
    strcpy(person.name, "John");

    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);

    struct LinkedList *head = NULL;
    
    add(&head, 3);
    add(&head, 4);
    rec_add_tail(&head, 5);
    add(&head, 1);
    add(&head, 2);
    add(&head, 3);

    display(&head);
    delete(&head, 4);
    printf("*** After Deleting 4 ***\n");
    display(&head);
    delete(&head, 3);
    printf("*** After Deleting 3 ***\n");
    display(&head);

    release(head);
}