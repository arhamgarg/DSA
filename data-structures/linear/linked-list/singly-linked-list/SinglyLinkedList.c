#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
// we can also have tail variable  which can reduce almost all the functions to O(n)
// and they will work similar to head variables

//--------------Core operations--------------

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int size(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void Traverse(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node *Update(struct Node *head, int updateValue, int newData)
{
    struct Node *temp = head;
    while (temp != NULL && temp->data != updateValue)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Node with given data: %d not found\n", updateValue);
        return head;
    }
    temp->data = newData;
    return head;
}

void Search(struct Node *head, int searchData)
{
    struct Node *temp = head;
    int pos = 0;
    while (temp != NULL)
    {
        if (temp->data == searchData)
        {
            printf("Data %d found at position %d\n", temp->data, pos);
            return; // stop at first match
        }
        temp = temp->next;
        pos++;
    }
    printf("Data %d not found\n", searchData);
}

int getAtIndex(struct Node *head, int index)
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

void isEmpty(struct Node *head)
{
    printf("List %s empty\n", head ? "isn't" : "is");
}
//--------------Insertion--------------

struct Node *insertFirst(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

struct Node *insertLast(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
        return newNode;
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node *insertAt(struct Node *head, int position, int value)
{
    if (position == 0)
        return insertFirst(head, value);

    struct Node *temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node *insertAfter(struct Node *head, int nodeData, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    struct Node *temp = head;
    while (temp != NULL && temp->data != nodeData)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node with given data: %d nor found", nodeData);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

//--------------Deletions--------------

struct Node *deleteFirst(struct Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        printf("Deleted value: %d\n", head->data);
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    printf("Deleted value: %d\n", temp->data);
    free(temp);
    return head;
}

struct Node *deleteLast(struct Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        printf("Deleted value: %d\n", head->data);
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    printf("Deleted value: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node *deleteAt(struct Node *head, int position)
{
    if (head == NULL)
        return NULL;
    if (position == 0)
        return deleteFirst(head);

    struct Node *temp = head;
    for (int i = 0; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    struct Node *toDelete = temp->next;
    temp->next = temp->next->next;
    printf("Deleted value: %d\n", toDelete->data);
    free(toDelete);
    return head;
}

struct Node *deleteKey(struct Node *head, int deleteData)
{
    if (head == NULL)
        return NULL;
    if (head->data == deleteData)
    {
        struct Node *temp = head;
        head = head->next;
        printf("Deleted value: %d\n", temp->data);
        free(temp);
        return head;
    }

    struct Node *prev = head;
    struct Node *toDelete = head->next;

    while (toDelete != NULL && toDelete->data != deleteData)
    {
        prev = toDelete;
        toDelete = toDelete->next;
    }
    if (toDelete == NULL)
    {
        printf("Node with given data: %d not found\n", deleteData);
        return head;
    }
    prev->next = toDelete->next;
    printf("Deleted value: %d\n", toDelete->data);
    free(toDelete);
    return head;
}

//--------------Utilities--------------

struct Node *Reverse(struct Node *head)
{
    if (head == NULL)
        return NULL;
    struct Node *prevNode = NULL;
    struct Node *currentNode = head;
    struct Node *nextNode = NULL;

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

int front(struct Node *head)
{
    if (head == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return head->data;
}

int last(struct Node *head)
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

struct Node *Copy(struct Node *head, struct Node *headCopy)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        headCopy = insertLast(headCopy, temp->data);
        temp = temp->next;
    }
    return headCopy;
}

void findMiddle(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *fast = head;
    struct Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("The middle value is: %d\n", slow->data);
}