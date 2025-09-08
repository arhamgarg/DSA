#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct dcl
{
    struct node *head;
    struct node *tail;
    int size;
};

struct dcl initList()
{
    struct dcl list = {NULL, NULL, 0};
    return list;
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void traverseForward(struct dcl *list)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *tempNode = list->head;
    do
    {
        printf("%d <-> ", tempNode->data);
        tempNode = tempNode->next;
    } while (tempNode != list->head);
    printf("(back to head)\n");
}

void traverseBackward(struct dcl *list)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *tempNode = list->tail;
    do
    {
        printf("%d <-> ", tempNode->data);
        tempNode = tempNode->prev;
    } while (tempNode != list->tail);
    printf("(back to tail)\n");
}

void isEmpty(struct dcl *list)
{
    printf("List %s empty\n", list->head ? "isn't" : "is");
}

void search(struct dcl *list, int searchData)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    int pos = 0;
    struct node *tempNode = list->head;
    do
    {
        if (tempNode->data == searchData)
        {
            printf("Data %d found at position %d\n", tempNode->data, pos);
            return;
        }
        pos++;
        tempNode = tempNode->next;
    } while (tempNode != list->head);
    printf("Data %d not found\n", searchData);
}

int front(struct dcl *list)
{
    if (list->head == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return list->head->data;
}

int back(struct dcl *list)
{
    if (list->tail == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return list->tail->data;
}

int size(struct dcl *list)
{
   return list->size;
}

struct node *insertFirst(struct dcl *list, int value)
{
    struct node *newNode = createNode(value);
    if (list->head == NULL)
    {
        list->head = list->tail = newNode;
        newNode->next = newNode->prev = newNode;
    }
    else
    {
        newNode->next = list->head;
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->size++;
    return list->head;
}

struct node *insertLast(struct dcl *list, int value)
{
    struct node *newNode = createNode(value);
    if (list->head == NULL)
    {
        list->head = list->tail = newNode;
        newNode->next = newNode->prev = newNode;
    }
    else
    {
        newNode->prev = list->tail;
        newNode->next = list->head;
        list->tail->next = newNode;
        list->head->prev = newNode;
        list->tail = newNode;
    }
    list->size++;
    return list->head;
}

struct node *insertAt(struct dcl *list, int position, int value)
{
    if (position == 0)
    {
        return insertFirst(list, value);
    }

    struct node *tempNode = list->head;
    int count = 0;
    while (count < position - 1 && tempNode->next != list->head)
    {
        tempNode = tempNode->next;
        count++;
    }

    if (position < 0 || position > list->size)
    {
        printf("Invalid position\n");
        return list->head;
    }

    struct node *newNode = createNode(value);
    newNode->next = tempNode->next;
    newNode->prev = tempNode;
    tempNode->next->prev = newNode;
    tempNode->next = newNode;

    if (tempNode == list->tail)
    {
        list->tail = newNode;
    }
    list->size++;
    return list->head;
}

struct node *deleteFirst(struct dcl *list)
{
    if (list->head == NULL)
        return NULL;
    struct node *tempNode = list->head;
    if (list->head == list->tail)
    {
        printf("Deleted value : %d\n", tempNode->data);
        free(tempNode);
        list->head = list->tail = NULL;
        return NULL;
    }
    printf("Deleted value : %d\n", tempNode->data);
    list->head = list->head->next;
    list->tail->next = list->head;
    list->head->prev = list->tail;

    free(tempNode);
    list->size--;
    return list->head;
}

struct node *deleteLast(struct dcl *list)
{
    if (list->head == NULL)
        return NULL;
    struct node *tempNode = list->tail;
    if (list->head == list->tail)
    {
        printf("Deleted value : %d\n", tempNode->data);
        free(tempNode);
        list->head = list->tail = NULL;
        return NULL;
    }

    printf("Deleted value : %d\n", tempNode->data);
    list->tail = list->tail->prev;
    list->tail->next = list->head;
    list->head->prev = list->tail;
    free(tempNode);
    list->size--;
    return list->head;
}

struct node *deleteAt(struct dcl *list, int position)
{
    if (list->head == NULL)
        return NULL;
    if (position == 0)
        return deleteFirst(list);

    struct node *tempNode = list->head;
    int count = 0;
    while (count < position - 1 && tempNode->next != list->head)
    {
        tempNode = tempNode->next;
        count++;
    }

    if (position < 0 || position >= list->size)
    {
        printf("Invalid position\n");
        return list->head;
    }

    struct node *toDelete = tempNode->next;
    printf("Deleted: %d\n", toDelete->data);

    tempNode->next = toDelete->next;
    toDelete->next->prev = tempNode;

    if (toDelete == list->tail)
        list->tail = tempNode;

    free(toDelete);
    list->size--;
    return list->head;
}

struct node *deleteKey(struct dcl *list, int deleteData)
{
    if (list->head == NULL)
        return NULL;

    struct node *tempNode = list->head;
    do
    {
        if (tempNode->data == deleteData)
        {
            if (tempNode == list->head && tempNode == list->tail)
            {
                printf("Deleted value: %d\n", tempNode->data);
                free(tempNode);
                list->head = list->tail = NULL;
                return NULL;
            }
            else if (tempNode == list->head)
                return deleteFirst(list);
            else if (tempNode == list->tail)
                return deleteLast(list);
            else
            {
                tempNode->prev->next = tempNode->next;
                tempNode->next->prev = tempNode->prev;
                printf("Deleted value: %d\n", tempNode->data);
                free(tempNode);
                list->size--;
                return list->head;
            }
        }
        tempNode = tempNode->next;
    } while (tempNode != list->head);

    printf("node with given data: %d not found\n", deleteData);
    return list->head;
}

struct node *update(struct dcl *list, int updateVal, int newData)
{
    if (list->head == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }

    struct node *tempNode = list->head;
    do
    {
        if (tempNode->data == updateVal)
        {
            tempNode->data = newData;
            printf("node updated: %d -> %d\n", updateVal, newData);
            return list->head;
        }
        tempNode = tempNode->next;
    } while (tempNode != list->head);
    printf("node with given data: %d not found\n", updateVal);
    return list->head;
}

struct node *reverse(struct dcl *list)
{
    if (list->head == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }
    struct node *current = list->head;
    struct node *tempNode = NULL;
    do
    {
        tempNode = current->prev;
        current->prev = current->next;
        current->next = tempNode;
        current = current->prev;
    } while (current != list->head);
    tempNode = list->head;
    list->head = list->tail;
    list->tail = tempNode;

    return list->head;
}
