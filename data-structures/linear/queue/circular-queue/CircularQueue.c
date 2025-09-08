#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct SCL
{
    struct node *head;
    struct node *tail;
    int size;
};

struct SCL initList()
{
    struct SCL list = {NULL, NULL, 0};
    return list;
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct node *enqueue(struct SCL *list, int value)
{
    struct node *newNode = createNode(value);
    if (list->head == NULL)
    {
        list->head = list->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        list->tail->next = newNode;
        newNode->next = list->head;
        list->tail = newNode;
    }
    list->size++;
    return list->head;
}

struct node *dequeue(struct SCL *list)
{
    if (list->head == NULL)
        return NULL;
    if (list->head == list->tail)
    {
        printf("Deleted value : %d\n", list->head->data);
        free(list->head);
        list->head = list->tail = NULL;
        list->size--;
        return NULL;
    }
    struct node *temp = list->head;
    list->head = list->head->next;
    list->tail->next = list->head;
    printf("Deleted value : %d\n", temp->data);
    free(temp);
    list->size--;
    return list->head;
}

void display(struct SCL *list)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *temp = list->head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(back to head)\n");
}
int front(struct SCL *list)
{
    if (list->head == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return list->head->data;
}

int back(struct SCL *list)
{
    if (list->tail == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return list->tail->data;
}

int size(struct SCL *list)
{
    return list->size;
}

bool isEmpty(struct SCL *list)
{
    return (list->head == NULL);
}