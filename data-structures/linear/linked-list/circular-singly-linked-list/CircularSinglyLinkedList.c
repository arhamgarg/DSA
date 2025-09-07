#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct scl
{
    struct node *head;
    struct node *tail;
};

struct scl initList()
{
    struct scl list = {NULL, NULL};
    return list;
}

struct node *createNode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void isEmpty(struct scl *list)
{
    printf("List %s empty\n", list->head ? "isn't" : "is");
}

void traverse(struct scl *list)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *tempNode = list->head;
    do
    {
        printf("%d -> ", tempNode->data);
        tempNode = tempNode->next;
    } while (tempNode != list->head);
    printf("(back to head)\n");
}
int front(struct scl *list)
{
    if (list->head == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return list->head->data;
}

int back(struct scl *list)
{
    if (list->tail == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return list->tail->data;
}

int size(struct scl *list)
{
    if (list->head == NULL)
        return 0;

    int count = 0;
    struct node *tempNode = list->head;
    do
    {
        count++;
        tempNode = tempNode->next;
    } while (tempNode != list->head);
    return count;
}

void search(struct scl *list, int searchData)
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

struct node *insertFirst(struct scl *list, int value)
{
    struct node *newnode = createNode(value);
    if (list->head == NULL)
    {
        list->head = list->tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = list->head;
        list->tail->next = newnode;
        list->head = newnode;
    }
    return list->head;
}

struct node *insertLast(struct scl *list, int value)
{
    struct node *newnode = createNode(value);
    if (list->head == NULL)
    {
        list->head = list->tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        list->tail->next = newnode;
        newnode->next = list->head;
        list->tail = newnode;
    }
    return list->head;
}

struct node *insertAt(struct scl *list, int position, int value)
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

    if (count != position - 1)
    {
        printf("Position out of range\n");
        return list->head;
    }

    struct node *newnode = createNode(value);
    newnode->next = tempNode->next;
    tempNode->next = newnode;

    if (tempNode == list->tail)
    {
        list->tail = newnode;
    }

    return list->head;
}

struct node *deleteFirst(struct scl *list)
{
    if (list->head == NULL)
        return NULL;
    if (list->head == list->tail)
    {
        printf("Deleted value : %d\n", list->head->data);
        free(list->head);
        list->head = list->tail = NULL;
        return NULL;
    }
    struct node *tempNode = list->head;
    list->head = list->head->next;
    list->tail->next = list->head;
    printf("Deleted value : %d\n", tempNode->data);
    free(tempNode);
    return list->head;
}

struct node *deleteLast(struct scl *list)
{
    if (list->head == NULL)
        return NULL;
    if (list->head == list->tail)
    {
        printf("Deleted value : %d\n", list->head->data);
        free(list->head);
        list->head = list->tail = NULL;
        return NULL;
    }
    struct node *tempNode = list->head;
    while (tempNode->next != list->tail)
        tempNode = tempNode->next;
    printf("Deleted value : %d\n", list->tail->data);
    free(list->tail);
    list->tail = tempNode;
    list->tail->next = list->head;
    return list->head;
}

struct node *deleteAt(struct scl *list, int position)
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

    if (count != position - 1 || tempNode->next == list->head)
    {
        printf("Position out of range\n");
        return list->head;
    }

    struct node *toDelete = tempNode->next;
    tempNode->next = toDelete->next;

    if (toDelete == list->tail)
    {
        list->tail = tempNode;
    }

    printf("Deleted value : %d\n", toDelete->data);
    free(toDelete);

    return list->head;
}

struct node *update(struct scl *list, int updateVal, int newData)
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