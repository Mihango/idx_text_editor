#ifndef __MALLOC_H
#define __MALLOC_H

typedef char ALIGN[16];

union header {
    struct {
        size_t size;
        unsigned int is_free;
        union header *next;
    } s;
    ALIGN stub;
};

typedef union header header_t;

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t num, size_t nsize);
void *realloc(void *block, size_t size);

#endif //__MALLOC_H;