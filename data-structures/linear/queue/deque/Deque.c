#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct deque
{
    struct node *front;
    struct node *rear;
    int size;
};

struct deque initList()
{
    struct deque dq = {NULL, NULL, 0};
    return dq;
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

struct node *insertFront(struct deque *dq, int value)
{
    struct node *newNode = createNode(value);
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

struct node *insertRear(struct deque *dq, int value)
{
    struct node *newNode = createNode(value);
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

struct node *deleteFront(struct deque *dq)
{
    if (dq->front == NULL)
    {
        printf("deque is empty\n");
        return NULL;
    }

    struct node *temp = dq->front;
    printf("Deleted value: %d\n", temp->data);

    dq->front = dq->front->next;

    if (dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->size--;
    return dq->front;
}

struct node *deleteRear(struct deque *dq)
{
    if (dq->front == NULL)
    {
        printf("deque is empty\n");
        return NULL;
    }

    struct node *temp = dq->rear;
    printf("Deleted value: %d\n", temp->data);
    dq->rear = dq->rear->prev;

    if (dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->size--;
    return dq->rear;
}

int getSize(struct deque *dq)
{
    return dq->size;
}

int getFront(struct deque *dq)
{
    if (dq->front == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return dq->front->data;
}

int getRear(struct deque *dq)
{
    if (dq->rear == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return dq->rear->data;
}

void traverseForward(struct deque *dq)
{
    struct node *temp = dq->front;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traverseBackward(struct deque *dq)
{
    struct node *temp = dq->rear;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

bool isEmpty(struct deque *dq)
{
    return (dq->front == NULL);
}