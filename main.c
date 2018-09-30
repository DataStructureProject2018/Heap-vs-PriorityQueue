//
// Created by paulo on 29/09/2018.
//

#include <stdio.h>
#include <time.h>
#include "./Heap/heap.h"
#include "./PriorityQueue/priorityQueue.h"

#define MAX 50000

int main() {

    srand(time(NULL));
    int i, contHeap = 1, contQueue = 1, num;

    FILE *heapFile = fopen("../heapFile.txt", "w");
    if(!heapFile) {
        printf("Failed to open heapFile\n");
        return 0;
    }
    FILE *queueFile = fopen("../queueFile.txt", "w");
    if(!queueFile) {
        printf("Failed to open queueFile\n");
        return 0;
    }

    Heap *heap = create_heap();
    PriorityQueue *queue = create_queue();

    for(i = 0; i < MAX; ++i) {
        num = rand();
        queue = enqueue(queue, num, &contQueue);
        add_node(heap, create_heapNode(num));
    }
    contQueue = 1;

    for(i = 0; i < 500; ++i) {
        num = rand() % 10000;
        queue = enqueue(queue, num, &contQueue);
        contHeap = add_node(heap, create_heapNode(num));
        fprintf(heapFile, "%d\n%d\n", num, contHeap);
        fprintf(queueFile, "%d\n%d\n", num, contQueue);
        contQueue = 1;
    }

    destroy_heap(heap);
    destroy_priority_queue(queue);

    fclose(heapFile);
    fclose(queueFile);

    return 0;
}
