#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct CircularQueue
{
    struct Node *head;
    struct Node *tail;
    int size;
};

struct CircularQueue initQueue()
{
    struct CircularQueue queue = {NULL, NULL, 0};
    return queue;
}

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node *enqueue(struct CircularQueue *queue, int value)
{
    struct Node *newNode = createNode(value);
    if (queue->head == NULL)
    {
        queue->head = queue->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        queue->tail->next = newNode;
        newNode->next = queue->head;
        queue->tail = newNode;
    }
    queue->size++;
    return queue->head;
}

struct Node *dequeue(struct CircularQueue *queue)
{
    if (queue->head == NULL)
        return NULL;
    if (queue->head == queue->tail)
    {
        printf("Deleted value : %d\n", queue->head->data);
        free(queue->head);
        queue->head = queue->tail = NULL;
        queue->size--;
        return NULL;
    }
    struct Node *tempNode = queue->head;
    queue->head = queue->head->next;
    queue->tail->next = queue->head;
    printf("Deleted value : %d\n", tempNode->data);
    free(tempNode);
    queue->size--;
    return queue->head;
}

void display(struct CircularQueue *queue)
{
    if (queue->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct Node *tempNode = queue->head;
    do
    {
        printf("%d -> ", tempNode->data);
        tempNode = tempNode->next;
    } while (tempNode != queue->head);
    printf("(back to head)\n");
}
int front(struct CircularQueue *queue)
{
    if (queue->head == NULL)
    {
        printf("queue empty\n");
        return -1;
    }
    return queue->head->data;
}

int rear(struct CircularQueue *queue)
{
    if (queue->tail == NULL)
    {
        printf("queue empty\n");
        return -1;
    }
    return queue->tail->data;
}

int getSize(struct CircularQueue *queue)
{
    return queue->size;
}

bool isEmpty(struct CircularQueue *queue)
{
    return (queue->head == NULL);
}