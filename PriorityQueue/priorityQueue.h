//
// Created by ricardo on 29/09/2018.
//

#ifndef HEAPVSPRIORITYQUEUE_PRIORITYQUEUE_H
#define HEAPVSPRIORITYQUEUE_PRIORITYQUEUE_H


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct priorityQueue {
    Node *head;
} PriorityQueue;

PriorityQueue* create_queue() {

    PriorityQueue *new_priority_queue = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    new_priority_queue->head = NULL;

    return new_priority_queue;

}

Node* create_node(int value) {

    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    return new_node;

}

PriorityQueue* enqueue(PriorityQueue *priorityQueue, int value, int *cont) {

    Node *node = create_node(value);
    Node *current = priorityQueue->head;
    Node *previous = NULL;

    while(current && current->value < value){
        *cont += 1;
        previous = current;
        current = current->next;
    }

    if(!previous){
        node->next = current;
        priorityQueue->head = node;
    }
    else {
        previous->next = node;
        node->next = current;
    }

    return priorityQueue;
}

void destroy_priority_queue(PriorityQueue *pq){
    Node *current = pq->head;
    Node *aux;

    while(current){
        aux = current;
        current = current->next;
        free(aux);
    }

    free(pq);

}

#endif //HEAPVSPRIORITYQUEUE_PRIORITYQUEUE_H
