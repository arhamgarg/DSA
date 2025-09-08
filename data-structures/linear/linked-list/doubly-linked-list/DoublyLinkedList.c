#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct dll
{
    struct node *head;
    struct node *tail;
    int size;
};

struct dll initList()
{
    struct dll list = {NULL, NULL, 0};
    return list;
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct node *insertFirst(struct dll *list, int value)
{
    struct node *newNode = createNode(value);

    if (list->head == NULL)
    {
        list->head = list->tail = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->size++;
    return list->head;
}

struct node *insertLast(struct dll *list, int value)
{
    struct node *newNode = createNode(value);

    if (list->tail == NULL)
    {
        list->head = list->tail = newNode;
    }
    else
    {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
    return list->head;
}

struct node *insertAfter(struct dll *list, int afterValue, int value)
{
    struct node *target = search(list, afterValue);
    if (target == NULL)
    {
        printf("Value %d not found\n", afterValue);
        return NULL;
    }

    if (target == list->tail)
        return insertLast(list, value);

    struct node *newNode = createNode(value);
    newNode->next = target->next;
    newNode->prev = target;
    target->next->prev = newNode;
    target->next = newNode;

    list->size++;
    return list->head;
}

struct node *insertAt(struct dll *list, int position, int value)
{
    if (position < 0 || position > list->size)
    {
        printf("Invalid position\n");
        return NULL;
    }

    if (position == 0)
        return insertFirst(list, value);
    if (position == list->size)
        return insertLast(list, value);

    struct node *tempNode = list->head;
    for (int i = 0; i < position - 1; i++)
    {
        tempNode = tempNode->next;
    }

    struct node *newNode = createNode(value);
    newNode->next = tempNode->next;
    newNode->prev = tempNode;
    tempNode->next->prev = newNode;
    tempNode->next = newNode;

    list->size++;
    return list->head;
}

struct node *deleteFirst(struct dll *list)
{
    if (list->head == NULL)
        return NULL;

    struct node *tempNode = list->head;
    if (list->head == list->tail)
    {
        list->head = list->tail = NULL;
    }
    else
    {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    printf("Deleted value: %d\n", tempNode->data);
    free(tempNode);
    list->size--;
    return list->head;
}

struct node *deleteLast(struct dll *list)
{
    if (list->tail == NULL)
        return NULL;

    struct node *tempNode = list->tail;
    if (list->head == list->tail)
    {
        list->head = list->tail = NULL;
    }
    else
    {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    printf("Deleted value: %d\n", tempNode->data);
    free(tempNode);
    list->size--;
    return list->head;
}

struct node *deleteAt(struct dll *list, int position)
{
    if (position < 0 || position >= list->size)
    {
        printf("Invalid position\n");
        return NULL;
    }

    if (position == 0)
        return deleteFirst(list);
    if (position == list->size - 1)
        return deleteLast(list);

    struct node *tempNode = list->head;
    for (int i = 0; i < position; i++)
    {
        tempNode = tempNode->next;
    }

    tempNode->prev->next = tempNode->next;
    tempNode->next->prev = tempNode->prev;

    printf("Deleted value: %d\n", tempNode->data);
    free(tempNode);
    list->size--;
    return list->head;
}

struct node *deleteKey(struct dll *list, int deleteData)
{
    if (list->head == NULL)
        return NULL;

    if (list->head->data == deleteData)
    {
        return deleteFirst(list);
    }

    struct node *tempNode = list->head;
    while (tempNode != NULL && tempNode->data != deleteData)
    {
        tempNode = tempNode->next;
    }

    if (tempNode == NULL)
    {
        printf("Data not found\n");
        return list->head;
    }

    if (tempNode == list->tail)
    {
        return deleteLast(list);
    }

    tempNode->prev->next = tempNode->next;
    tempNode->next->prev = tempNode->prev;

    printf("Deleted value: %d\n", tempNode->data);
    free(tempNode);
    list->size--;
    return list->head;
}

struct node *search(struct dll *list, int value)
{
    struct node *tempNode = list->head;
    while (tempNode != NULL)
    {
        if (tempNode->data == value)
        {
            return tempNode;
        }
        tempNode = tempNode->next;
    }
    return NULL;
}

struct node *update(struct dll *list, int oldValue, int newValue)
{
    struct node *tempNode = search(list, oldValue);
    if (tempNode != NULL)
    {
        tempNode->data = newValue;
        return tempNode;
    }
    printf("Value not found\n");
    return NULL;
}

struct node *reverse(struct dll *list)
{
    struct node *curr = list->head;
    struct node *tempNode = NULL;

    while (curr != NULL)
    {
        tempNode = curr->prev;
        curr->prev = curr->next;
        curr->next = tempNode;
        curr = curr->prev;
    }

    if (tempNode != NULL)
    {
        list->tail = list->head;
        list->head = tempNode->prev;
    }
    return list->head;
}

struct node *copy(struct dll *list, struct dll *copyList)
{
    *copyList = initList();
    struct node *tempNode = list->head;
    while (tempNode != NULL)
    {
        insertLast(copyList, tempNode->data);
        tempNode = tempNode->next;
    }
    return copyList->head;
}

void traverseForward(struct dll *list)
{
    struct node *tempNode = list->head;
    while (tempNode != NULL)
    {
        printf("%d <-> ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("NULL\n");
}

void traverseBackward(struct dll *list)
{
    struct node *tempNode = list->tail;
    while (tempNode != NULL)
    {
        printf("%d <-> ", tempNode->data);
        tempNode = tempNode->prev;
    }
    printf("NULL\n");
}

void isEmpty(struct dll *list)
{
    if (list->head == NULL)
        printf("List is empty\n");
    else
        printf("List isn't empty\n");
}

int getSize(struct dll *list)
{
    return list->size;
}
