#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct stack
{
    struct node *head;
    int size;
};

struct stack initList()
{
    struct stack list = {NULL, 0};
    return list;
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct node *push(struct stack *list, int value)
{
    struct node *newNode = createNode(value);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
    return list->head;
}

struct node *pop(struct stack *list)
{
    if (list->head == NULL)
        return NULL;

    struct node *tempNode = list->head;
    list->head = list->head->next;
    printf("Deleted value: %d\n", tempNode->data);
    list->size--;
    free(tempNode);
    return list->head;
}

bool isEmpty(struct stack *list)
{
    return list->head == NULL;
}

int size(struct stack *list)
{
    return list->size;
}

int top(struct stack *list)
{
    if (list->head == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return list->head->data;
}

void display(struct stack *list)
{
    struct node *temp = list->head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}