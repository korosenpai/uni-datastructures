#ifndef HEAP_H
#define HEAP_H

typedef struct {
    int heap_size; // number of current elements in heap
    int h[]; // arr that will function as heap
} Heap;

Heap* init_heap(int heapSize);
void heapSetArray(Heap* h, int arr[], int size);

void heapPrint(Heap* h);

int PARENT(int i);
int LEFT(int i);
int RIGHT(int i);

void maxHeapify(Heap* h, int i);

void buildMaxHeap(Heap* h, int n);

void heapSort(Heap* h, int n);

#endif
