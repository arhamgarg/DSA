#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *head;
    int size;
};

struct queue initList()
{
    struct queue list = {NULL, 0};
    return list;
}

struct node *
createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct node *enqueue(struct queue *list, int value)
{
    struct node *newNode = createNode(value);
    if (list->head == NULL)
    {
        list->head = newNode;
        list->size++;
        return list->head;
    }
    struct node *tempNode = list->head;
    while (tempNode->next != NULL)
        tempNode = tempNode->next;
    tempNode->next = newNode;
    list->size++;
    return list->head;
}

struct node *dequeue(struct queue *list)
{
    if (list->head == NULL)
        return NULL;

    struct node *tempNode = list->head;
    list->head = list->head->next;
    printf("Deleted value: %d\n", tempNode->data);
    free(tempNode);
    list->size--;
    return list->head;
}

int size(struct queue *list)
{
    return list->size;
}

int front(struct queue *list)
{
    if (list->head == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return list->head->data;
}

void display(struct queue *list)
{
    struct node *temp = list->head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

bool isEmpty(struct queue *list)
{
    return list->head == NULL;
}
