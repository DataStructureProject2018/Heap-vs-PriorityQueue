//
// Created by paulo on 29/09/2018.
//

#ifndef HEAPVSPRIORITYQUEUE_HEAP_H
#define HEAPVSPRIORITYQUEUE_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEAP_SIZE 65534

typedef struct heapNode {
    int value;
} HeapNode;

typedef struct heap {
    int size;
    HeapNode *data[MAX_HEAP_SIZE];
} Heap;

// Cria uma Heap
Heap* create_heap() {

    Heap *new_heap = (Heap *) malloc(sizeof(Heap));
    new_heap->size = 0;

    int i;
    for(i = 1; i <= MAX_HEAP_SIZE; i++){
        new_heap->data[i] = NULL;
    }

    return new_heap;

}


HeapNode *create_heapNode(int value) {

    HeapNode *new_node = (HeapNode *)malloc(sizeof(HeapNode));
    new_node->value = value;

    return new_node;

}


// Retorna a posição do Pai do índice i
int get_parent_index(int i) {

    return (i >> 1);

}

// Retorna a posição do Filho da esquerda do nó de índice i
int get_left_index(int i) {

    return (i << 1);

}

// Retorna a posição do Filho da direita do nó de índice i
int get_right_index(int i) {

    return (i << 1)+1;

}

void swap_nodes(HeapNode **first, HeapNode **second) {

    HeapNode *aux = *first;
    *first = *second;
    *second = aux;

}

// Adiciona novo node na Heap
int add_node(Heap *heap, HeapNode *node) {
    int cont = 1;
    heap->data[++heap->size] = node;

    int key_index = heap->size;
    int parent_index = get_parent_index(heap->size);

    while(parent_index >= 1 && heap->data[key_index]->value <= heap->data[parent_index]->value){
        cont++;
        swap_nodes(&heap->data[key_index], &heap->data[parent_index]);
        key_index = parent_index;
        parent_index = get_parent_index(key_index);
    }

    return cont;
}

void printHeap(Heap *heap) {
    int i;

    for(i = 1; i <= heap->size; ++i) {
        printf("%d ", heap->data[i]->value);
    }

}

int min_heapify(Heap *heap, int i, int cont) {

    int smallest = i;
    int leftIndex = get_left_index(i);
    int rightIndex = get_right_index(i);

    // Verificamos se o filho da esquerda é menor do que o pai dele
    if(leftIndex <= heap->size && heap->data[leftIndex]->value <= heap->data[i]->value) {
        cont++;
        smallest = leftIndex;
    }

    // Verificamos se o filho da direita é menor do que o da esquerda (caso o da esquerda seja menor do que o pai)
    if(rightIndex <= heap->size && heap->data[rightIndex]->value <= heap->data[smallest]->value) {
        cont++;
        smallest = rightIndex;
    }

    // Caso tenhamos achado um filho menor, trocamos ele com o pai e continuamos a arrumar a heap
    if(smallest != i) {
        swap_nodes(&heap->data[i], &heap->data[smallest]);

        return min_heapify(heap, smallest, cont);
    }
    else{
        return cont;
    }

}

int remove_heap(Heap *heap, int cont) {

    int removed = heap->data[1]->value;
    heap->data[1] = heap->data[heap->size];
    heap->data[heap->size] = NULL;
    heap->size--;

    return min_heapify(heap, 1, cont);

}

void destroy_heap(Heap *heap) {

    int i;
    for(i = 1; i < MAX_HEAP_SIZE; i++) {
        if(heap->data[i]) {
            free(heap->data[i]);
        }
    }

    free(heap);

};




#endif //HEAPVSPRIORITYQUEUE_HEAP_H
