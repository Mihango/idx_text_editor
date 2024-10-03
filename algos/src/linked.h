#ifndef LINKED_H
#define LINKED_H

struct LinkedList {
    int value;
    struct LinkedList *next;
};

void add(struct LinkedList **head, int val);
void rec_add_tail(struct LinkedList **head, int val);
void delete(struct LinkedList **head, int val);
struct LinkedList* search(struct LinkedList *head, int val);
void display(struct LinkedList **head);
void release(struct LinkedList *head);

#endif