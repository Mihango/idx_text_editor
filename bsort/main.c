#include <stdio.h>

void bsort(int arr[], int n);
void swap(int arr[], int i, int j);
void display(int arr[], int size);

int main() {
    printf("**** Bubble Sort ****\n");
    int arr[] = {43, 54, 2, 13, 33};
    int size = sizeof(arr) / sizeof(int);
    printf("Size of arr: %d: \n", size);
    display(arr, size);
    bsort(arr, size);
    display(arr, size);
    return 0;
}

void bsort(int arr[], int n) {
    for(int i =0; i < n - 1; i++) {
        for(int j = i +1; j < n - i; j++) {
            if(arr[i] > arr[j]) {
                swap(arr, i, j);
            }
        }
    }
}

void swap (int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void display(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}