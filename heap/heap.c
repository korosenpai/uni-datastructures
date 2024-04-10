#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"

// heap has to be freed after use
// NOTE: assumes all elements are >= 0
Heap* init_heap(int heapSize) {
    // automatically allocate a heap of max size heapSize
    Heap* h = malloc(sizeof(Heap) + heapSize * sizeof(int));

    // NOTE: set all empty cells to -1
    for (int i = 0; i < heapSize; i++)
        h->h[i] = -1;

    return h;
    
};

// set h value of struct
// will discard values held before
// NOTE: this assumes arr is NEVER emtpy
// and this cant overflow with initial array size
void heapSetArray(Heap* h, int arr[], int size) {
    h->heap_size = size;
    memcpy(h->h, arr, h->heap_size * sizeof(int));
}


void heapPrint(Heap* h) {
    printf("heapSize: %d\t", h->heap_size);
    printf("heap:");
    for (int i = 0; i < h->heap_size; i++)
        printf(" %d", h->h[i]);
    printf("\n");
}


int PARENT(int i) {
    return i/2;
}
int LEFT(int i) {
    return 2 * i;
}
int RIGHT(int i) {
    return 2 * i + 1;
}

// ensure property of heap from index i downwards
void maxHeapify(Heap* h, int i) {
    //printf("itering using: %d\n", i);
    int* arr = h->h; // pointer to h->h to simplify reading code

    int largest; // index of largest element
    int l = LEFT(i) - 1; // -1 because it is 1 indexed
    int r = RIGHT(i) - 1;
    i--;

    if (l < h->heap_size && arr[l] > arr[i]) {
        largest = l;
    }
    else largest = i;

    if (r < h->heap_size && arr[r] > arr[largest]) {
        largest = r;
    }

    //heapPrint(h);
    //printf("largest: %d, %d\n", largest, arr[largest]);
if (largest != i) {
        // swap arr[i] with arr[largest]
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;

        maxHeapify(h, largest + 1); // + 1 to 1 index it again
    }

}


// transform array to heap traversing bottom up
void buildMaxHeap(Heap* h, int n) {
    h->heap_size = n;
    for (int i = n / 2; i >= 1; i--) {
        maxHeapify(h, i);
    }

}

void heapSort(Heap* h, int n) {
    int originalSize = h->heap_size; // to restore later at it will get set to 1

    buildMaxHeap(h, n);
    for (int i = n; i >= 2; i--) {
        //swap a[1] with a[i]
        int tmp = h->h[i - 1];
        h->h[i - 1] = h->h[0];
        h->h[0] = tmp;

        h->heap_size--;
        maxHeapify(h, 1);
    }

    h->heap_size = originalSize;

}
