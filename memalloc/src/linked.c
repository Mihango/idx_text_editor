#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

void add(struct LinkedList **head, int val) {
    struct LinkedList *node = malloc(sizeof(struct LinkedList));
    node->value = val;
    node->next = *head;
    *head = node;
}

void rec_add_tail(struct LinkedList **head, int val) {
    if(head != NULL && (*head)->next != NULL) 
        rec_add_tail(&(*head)->next, val);
   
    struct LinkedList *node = malloc(sizeof(struct LinkedList));
    node->next = NULL;
    node->value = val;

    if(head == NULL) {
        *head = node;
    } else {
        (*head)->next = node;
    }
}

struct LinkedList* search(struct LinkedList *head, int val) {
    struct LinkedList *curr = head;

    while(curr != NULL) {
        if(curr->value == val) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void delete(struct LinkedList **head, int val) {
    struct LinkedList *prev = NULL;
    struct LinkedList *curr = *head;

    while(curr != NULL) {
        if(curr->value == val) {
            if(prev == NULL) {
                *head = curr->next;
                return;
            } else {
                prev->next = curr->next;
                return;
            }
        }
        prev = curr;
        curr = curr->next;
    }
}

void display(struct LinkedList **head) {
    struct LinkedList *curr = *head;

    while(curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

void release(struct LinkedList *head) {
    struct LinkedList *curr = head;

    while(curr != NULL) {
        struct LinkedList *next = curr->next;
        free(curr);
        curr = next;
    }
}