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

PriorityQueue* enqueue(PriorityQueue *priorityQueue, int value) {

    Node *node = create_node(value);
    Node *current = priorityQueue->head;
    Node *previous = NULL;

    while(current && current->value < value){
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

int achei(PriorityQueue *priorityQueue, int value) {

    int cont = 0;
    Node *current = priorityQueue->head;

    while(current && current->value != value){
        current = current->next;
        ++cont;
    }

    return cont;

}

void print_pq(PriorityQueue *pq){
    Node *current = pq->head;

    while(current){
        printf("%d ", current->value);
        current = current->next;
    }

}

#endif //HEAPVSPRIORITYQUEUE_PRIORITYQUEUE_H
