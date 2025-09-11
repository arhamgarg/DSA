#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *head;
    int size;
};

struct Stack initStack()
{
    struct Stack stack = {NULL, 0};
    return stack;
}

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node *push(struct Stack *stack, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = stack->head;
    stack->head = newNode;
    stack->size++;
    return stack->head;
}

struct Node *pop(struct Stack *stack)
{
    if (stack->head == NULL)
        return NULL;

    struct Node *tempNode = stack->head;
    stack->head = stack->head->next;
    printf("Deleted value: %d\n", tempNode->data);
    stack->size--;
    free(tempNode);
    return stack->head;
}

bool isEmpty(struct Stack *stack)
{
    return stack->head == NULL;
}

int getSize(struct Stack *stack)
{
    return stack->size;
}

int top(struct Stack *stack)
{
    if (stack->head == NULL)
    {
        printf("stack empty\n");
        return -1;
    }
    return stack->head->data;
}

void display(struct Stack *stack)
{
    struct Node *temp = stack->head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}