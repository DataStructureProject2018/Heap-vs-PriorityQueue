//
// Created by paulo on 29/09/2018.
//

#include <stdio.h>
#include "./Heap/heap.h"

int main() {

    int i;

    Heap *heap = create_heap();

    FILE *in = fopen("../array.txt", "r");
    if(!in) {
        printf("Error opening file...\n");
        return 0;
    }

    fscanf(in, "%d", &i);
    while(!feof(in)) {
        if(!feof(in)) {
            heap = add_node(heap, create_heapNode(i));
            fscanf(in, "%d", &i);
        }
    }

    //printHeap(heap);

    search(heap, 2);

    destroy_heap(heap);
    fclose(in);

    return 0;
}