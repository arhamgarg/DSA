#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *head;
    int size;
};

struct Queue initList()
{
    struct Queue list = {NULL, 0};
    return list;
}

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node *enqueue(struct Queue *list, int value)
{
    struct Node *newNode = createNode(value);
    if (list->head == NULL)
    {
        list->head = newNode;
        list->size++;
        return list->head;
    }
    struct Node *tempNode = list->head;
    while (tempNode->next != NULL)
        tempNode = tempNode->next;
    tempNode->next = newNode;
    list->size++;
    return list->head;
}

struct Node *dequeue(struct Queue *list)
{
    if (list->head == NULL)
        return NULL;

    struct Node *tempNode = list->head;
    list->head = list->head->next;
    printf("Deleted value: %d\n", tempNode->data);
    free(tempNode);
    list->size--;
    return list->head;
}

int getSize(struct Queue *list)
{
    return list->size;
}

int front(struct Queue *list)
{
    if (list->head == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return list->head->data;
}

void display(struct Queue *list)
{
    struct Node *temp = list->head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

bool isEmpty(struct Queue *list)
{
    return list->head == NULL;
}
