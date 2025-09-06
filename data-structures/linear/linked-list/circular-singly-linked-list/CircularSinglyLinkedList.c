#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct SCL
{
    struct Node *head;
    struct Node *tail;
};

struct SCL initList()
{
    struct SCL list = {NULL, NULL};
    return list;
}

//-------------Core-Operations-------------

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void isEmpty(struct SCL *list)
{
    printf("List %s empty\n", list->head ? "isn't" : "is");
}

void Traverse(struct SCL *list)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct Node *temp = list->head;
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
    if (list->head == NULL)
        return 0;

    int count = 0;
    struct Node *temp = list->head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != list->head);
    return count;
}

void Search(struct SCL *list, int searchData)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    int pos = 0;
    struct Node *temp = list->head;
    do
    {
        if (temp->data == searchData)
        {
            printf("Data %d found at position %d\n", temp->data, pos);
            return;
        }
        pos++;
        temp = temp->next;
    } while (temp != list->head);
    printf("Data %d not found\n", searchData);
}

//-------------Insertions-------------

struct Node *insertFirst(struct SCL *list, int value)
{
    struct Node *newNode = createNode(value);
    if (list->head == NULL)
    {
        list->head = list->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->tail->next = newNode;
        list->head = newNode;
    }
    return list->head;
}

struct Node *insertLast(struct SCL *list, int value)
{
    struct Node *newNode = createNode(value);
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
    return list->head;
}

struct Node *insertAt(struct SCL *list, int position, int value)
{
    if (position == 0)
    {
        return insertFirst(list, value);
    }

    struct Node *temp = list->head;
    int count = 0;
    while (count < position - 1 && temp->next != list->head)
    {
        temp = temp->next;
        count++;
    }

    if (count != position - 1)
    {
        printf("Position out of range\n");
        return list->head;
    }

    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == list->tail)
    { // inserted at the end
        list->tail = newNode;
    }

    return list->head;
}

//-------------Deletions-------------

struct Node *deleteFirst(struct SCL *list)
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
    struct Node *temp = list->head;
    list->head = list->head->next;
    list->tail->next = list->head;
    printf("Deleted value : %d\n", temp->data);
    free(temp);
    return list->head;
}

struct Node *deleteLast(struct SCL *list)
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
    struct Node *temp = list->head;
    while (temp->next != list->tail)
        temp = temp->next;
    printf("Deleted value : %d\n", list->tail->data);
    free(list->tail);
    list->tail = temp;
    list->tail->next = list->head;
    return list->head;
}

struct Node *deleteAt(struct SCL *list, int position)
{
    if (list->head == NULL)
        return NULL;
    if (position == 0)
        return deleteFirst(list);

    struct Node *temp = list->head;
    int count = 0;
    while (count < position - 1 && temp->next != list->head)
    {
        temp = temp->next;
        count++;
    }

    if (count != position - 1 || temp->next == list->head)
    {
        printf("Position out of range\n");
        return list->head;
    }

    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;

    if (toDelete == list->tail)
    {
        list->tail = temp;
    }

    printf("Deleted value : %d\n", toDelete->data);
    free(toDelete);

    return list->head;
}

//-------------Utilties-------------
struct Node *Update(struct SCL *list, int updateVal, int newData)
{
    if (list->head == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }

    struct Node *temp = list->head;
    do
    {
        if (temp->data == updateVal)
        {
            temp->data = newData;
            printf("Node updated: %d -> %d\n", updateVal, newData);
            return list->head;
        }
        temp = temp->next;
    } while (temp != list->head);
    printf("Node with given data: %d not found\n", updateVal);
    return list->head;
}