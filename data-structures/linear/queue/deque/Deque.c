#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Deque
{
    struct Node *front;
    struct Node *rear;
    int size;
};

struct Deque initQueue()
{
    struct Deque dq = {NULL, NULL, 0};
    return dq;
}

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

struct Node *insertFront(struct Deque *dq, int value)
{
    struct Node *newNode = createNode(value);
    if (dq->front == NULL)
        dq->front = dq->rear = newNode;
    else
    {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->size++;
    return newNode;
}

struct Node *insertRear(struct Deque *dq, int value)
{
    struct Node *newNode = createNode(value);
    if (dq->front == NULL)
        dq->front = dq->rear = newNode;
    else
    {
        dq->rear->next = newNode;
        newNode->prev = dq->rear;
        dq->rear = newNode;
    }
    dq->size++;
    return newNode;
}

struct Node *deleteFront(struct Deque *dq)
{
    if (dq->front == NULL)
    {
        printf("Deque is empty\n");
        return NULL;
    }

    struct Node *tempNode = dq->front;
    printf("Deleted value: %d\n", tempNode->data);

    dq->front = dq->front->next;

    if (dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(tempNode);
    dq->size--;
    return dq->front;
}

struct Node *deleteRear(struct Deque *dq)
{
    if (dq->front == NULL)
    {
        printf("Deque is empty\n");
        return NULL;
    }

    struct Node *tempNode = dq->rear;
    printf("Deleted value: %d\n", tempNode->data);
    dq->rear = dq->rear->prev;

    if (dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(tempNode);
    dq->size--;
    return dq->rear;
}

int getSize(struct Deque *dq)
{
    return dq->size;
}

int getFront(struct Deque *dq)
{
    if (dq->front == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return dq->front->data;
}

int getRear(struct Deque *dq)
{
    if (dq->rear == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return dq->rear->data;
}

void traverseForward(struct Deque *dq)
{
    struct Node *tempNode = dq->front;
    while (tempNode != NULL)
    {
        printf("%d <-> ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("NULL\n");
}

void traverseBackward(struct Deque *dq)
{
    struct Node *tempNode = dq->rear;
    while (tempNode != NULL)
    {
        printf("%d <-> ", tempNode->data);
        tempNode = tempNode->prev;
    }
    printf("NULL\n");
}

bool isEmpty(struct Deque *dq)
{
    return (dq->front == NULL);
}