#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int size(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct node *update(struct node *head, int updateValue, int newData)
{
    struct node *tempNode = head;
    while (tempNode != NULL && tempNode->data != updateValue)
        tempNode = tempNode->next;

    if (tempNode == NULL)
    {
        printf("node with given data: %d not found\n", updateValue);
        return head;
    }
    tempNode->data = newData;
    return head;
}

void search(struct node *head, int searchData)
{
    struct node *tempNode = head;
    int pos = 0;
    while (tempNode != NULL)
    {
        if (tempNode->data == searchData)
        {
            printf("Data %d found at position %d\n", tempNode->data, pos);
            return;
        }
        tempNode = tempNode->next;
        pos++;
    }
    printf("Data %d not found\n", searchData);
}

int getAtIndex(struct node *head, int index)
{
    int indexCounter = 0;
    while (head != NULL)
    {
        if (index == indexCounter)
            return head->data;
        head = head->next;
        indexCounter++;
    }
    printf("Index out of range\n");
    return -1;
}

void isEmpty(struct node *head)
{
    printf("List %s empty\n", head ? "isn't" : "is");
}

struct node *insertFirst(struct node *head, int value)
{
    struct node *newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

struct node *insertLast(struct node *head, int value)
{
    struct node *newNode = createNode(value);
    if (head == NULL)
        return newNode;
    struct node *tempNode = head;
    while (tempNode->next != NULL)
        tempNode = tempNode->next;
    tempNode->next = newNode;
    return head;
}

struct node *insertAt(struct node *head, int position, int value)
{
    if (position == 0)
        return insertFirst(head, value);

    struct node *tempNode = head;
    for (int i = 0; i < position - 1 && tempNode != NULL; i++)
        tempNode = tempNode->next;

    if (tempNode == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    struct node *newNode = createNode(value);
    newNode->next = tempNode->next;
    tempNode->next = newNode;
    return head;
}

struct node *insertAfter(struct node *head, int nodeData, int data)
{
    struct node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    struct node *tempNode = head;
    while (tempNode != NULL && tempNode->data != nodeData)
    {
        tempNode = tempNode->next;
    }
    if (tempNode == NULL)
    {
        printf("node with given data: %d nor found", nodeData);
        return head;
    }
    newNode->next = tempNode->next;
    tempNode->next = newNode;
    return head;
}

struct node *deleteFirst(struct node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        printf("Deleted value: %d\n", head->data);
        free(head);
        return NULL;
    }
    struct node *tempNode = head;
    head = head->next;
    printf("Deleted value: %d\n", tempNode->data);
    free(tempNode);
    return head;
}

struct node *deleteLast(struct node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        printf("Deleted value: %d\n", head->data);
        free(head);
        return NULL;
    }
    struct node *tempNode = head;
    while (tempNode->next->next != NULL)
        tempNode = tempNode->next;
    printf("Deleted value: %d\n", tempNode->next->data);
    free(tempNode->next);
    tempNode->next = NULL;
    return head;
}

struct node *deleteAt(struct node *head, int position)
{
    if (head == NULL)
        return NULL;
    if (position == 0)
        return deleteFirst(head);

    struct node *tempNode = head;
    for (int i = 0; i < position - 1 && tempNode->next != NULL; i++)
        tempNode = tempNode->next;

    if (tempNode->next == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    struct node *toDelete = tempNode->next;
    tempNode->next = tempNode->next->next;
    printf("Deleted value: %d\n", toDelete->data);
    free(toDelete);
    return head;
}

struct node *deleteKey(struct node *head, int deleteData)
{
    if (head == NULL)
        return NULL;
    if (head->data == deleteData)
    {
        struct node *tempNode = head;
        head = head->next;
        printf("Deleted value: %d\n", tempNode->data);
        free(tempNode);
        return head;
    }

    struct node *prev = head;
    struct node *toDelete = head->next;

    while (toDelete != NULL && toDelete->data != deleteData)
    {
        prev = toDelete;
        toDelete = toDelete->next;
    }
    if (toDelete == NULL)
    {
        printf("node with given data: %d not found\n", deleteData);
        return head;
    }
    prev->next = toDelete->next;
    printf("Deleted value: %d\n", toDelete->data);
    free(toDelete);
    return head;
}

struct node *reverse(struct node *head)
{
    if (head == NULL)
        return NULL;
    struct node *prevNode = NULL;
    struct node *currentNode = head;

    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    return head;
}

int front(struct node *head)
{
    if (head == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return head->data;
}

int last(struct node *head)
{
    if (head == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    while (head->next != NULL)
        head = head->next;
    return head->data;
}

struct node *copy(struct node *head, struct node *headCopy)
{
    struct node *tempNode = head;
    while (tempNode != NULL)
    {
        headCopy = insertLast(headCopy, tempNode->data);
        tempNode = tempNode->next;
    }
    return headCopy;
}

void findMiddle(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *fast = head;
    struct node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("The middle value is: %d\n", slow->data);
}