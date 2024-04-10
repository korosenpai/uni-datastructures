#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"


int demo() {
    int n = 3;
    Heap* h = init_heap(n);
    if (h == NULL) return -1;

    // set an array as the heap
    int hValues[] = {10, 11, 12, 13};
    heapSetArray(h, hValues, sizeof(hValues) / sizeof(hValues[0]));

    heapPrint(h);

    printf("%d\n", RIGHT(4));

    free(h);

    return 0;
}

// example 6.2 page 148
int exerciseMaxHeapify() {
    int hValues[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int size = sizeof(hValues) / sizeof(hValues[0]);

    Heap* h = init_heap(size);
    if (h == NULL) return -1;

    heapSetArray(h, hValues, size);

    heapPrint(h);

    maxHeapify(h, 2); // 1 indexed

    printf("after ensuring properties of heap:\n");
    heapPrint(h);

    free(h);

    return 0;
}

// example 6.3
int exerciseBuildMaxHeap() {
    int hValues[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int size = sizeof(hValues) / sizeof(hValues[0]);

    Heap* h = init_heap(size);
    if (h == NULL) return -1;

    heapSetArray(h, hValues, size);

    heapPrint(h);

    buildMaxHeap(h, size);

    printf("after building heap:\n");
    heapPrint(h);



    free(h);

    return 0;
}

int exerciseHeapSort() {
    int hValues[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int size = sizeof(hValues) / sizeof(hValues[0]);

    Heap* h = init_heap(size);
    if (h == NULL) return -1;

    heapSetArray(h, hValues, size);

    heapPrint(h);

    heapSort(h, size);

    printf("sorted heap:\n");
    heapPrint(h);


    free(h);

    return 0;

}

int main() {
    // demo();
    // exerciseMaxHeapify();
    // exerciseBuildMaxHeap();
    exerciseHeapSort();

    return 0;
}
