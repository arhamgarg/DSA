#include <stdio.h>
#include <stdlib.h>

// ---------------- Node Definition ----------------
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// ---------------- List Definition ----------------
struct DLL
{
    struct Node *head;
    struct Node *tail;
    int size;
};

// ---------------- Initialization ----------------
struct DLL initList()
{
    struct DLL list = {NULL, NULL, 0};
    return list;
}

// ---------------- Node Creation ----------------
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// ---------------- Insert Operations ----------------
struct Node *insertFirst(struct DLL *list, int value)
{
    struct Node *newNode = createNode(value);

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
    return newNode;
}

struct Node *insertLast(struct DLL *list, int value)
{
    struct Node *newNode = createNode(value);

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
    return newNode;
}

struct Node *insertAt(struct DLL *list, int position, int value)
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

    struct Node *temp = list->head;
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }

    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    list->size++;
    return newNode;
}

// ---------------- Delete Operations ----------------
struct Node *deleteFirst(struct DLL *list)
{
    if (list->head == NULL)
        return NULL;

    struct Node *temp = list->head;
    if (list->head == list->tail)
    {
        list->head = list->tail = NULL;
    }
    else
    {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    printf("Deleted value: %d\n", temp->data);
    free(temp);
    list->size--;
    return list->head;
}

struct Node *deleteLast(struct DLL *list)
{
    if (list->tail == NULL)
        return NULL;

    struct Node *temp = list->tail;
    if (list->head == list->tail)
    {
        list->head = list->tail = NULL;
    }
    else
    {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    printf("Deleted value: %d\n", temp->data);
    free(temp);
    list->size--;
    return list->tail;
}

struct Node *deleteAt(struct DLL *list, int position)
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

    struct Node *temp = list->head;
    for (int i = 0; i < position; i++)
    {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted value: %d\n", temp->data);
    free(temp);
    list->size--;
    return list->head;
}

struct Node *deleteKey(struct DLL *list, int deletedata)
{
    if (list->head == NULL)
        return NULL;

    if (list->head->data == deletedata)
    {
        return deleteFirst(list);
    }

    struct Node *temp = list->head;
    while (temp != NULL && temp->data != deletedata)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Data not found\n");
        return NULL;
    }

    if (temp == list->tail)
    {
        return deleteLast(list);
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted value: %d\n", temp->data);
    free(temp);
    list->size--;
    return list->head;
}

// ---------------- Search ----------------
struct Node *search(struct DLL *list, int value)
{
    struct Node *temp = list->head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// ---------------- Update ----------------
struct Node *update(struct DLL *list, int oldValue, int newValue)
{
    struct Node *temp = search(list, oldValue);
    if (temp != NULL)
    {
        temp->data = newValue;
        return temp;
    }
    printf("Value not found\n");
    return NULL;
}

// ---------------- Reverse ----------------
struct Node *Reverse(struct DLL *list)
{
    struct Node *curr = list->head;
    struct Node *temp = NULL;

    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
    {
        list->head = temp->prev;
    }

    // swap head and tail
    temp = list->head;
    list->head = list->tail;
    list->tail = temp;

    return list->head;
}

// ---------------- Copy ----------------
struct Node *Copy(struct DLL *list, struct DLL *copyList)
{
    struct Node *temp = list->head;
    while (temp != NULL)
    {
        insertLast(copyList, temp->data);
        temp = temp->next;
    }
    return copyList->head;
}

// ---------------- Utilities ----------------
void traverseForward(struct DLL *list)
{
    struct Node *temp = list->head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traverseBackward(struct DLL *list)
{
    struct Node *temp = list->tail;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void isEmpty(struct DLL *list)
{
    if (list->head == NULL)
        printf("List is empty\n");
    else
        printf("List isn't empty\n");
}

int size(struct DLL *list)
{
    return list->size;
}