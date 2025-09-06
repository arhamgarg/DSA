#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct DCL
{
    struct Node *head;
    struct Node *tail;
};

struct DCL initList()
{
    struct DCL list = {NULL, NULL};
    return list;
}
//-------------Core-operations-------------

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void TraverseForward(struct DCL *list)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct Node *temp = list->head;
    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(back to head)\n");
}

void TraverseBackward(struct DCL *list)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct Node *temp = list->tail;
    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != list->tail);
    printf("(back to tail)\n");
}

void isEmpty(struct DCL *list)
{
    printf("List %s empty\n", list->head ? "isn't" : "is");
}

void Search(struct DCL *list, int searchData)
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
// 😎📔
int front(struct DCL *list)
{
    if (list->head == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return list->head->data;
}

int back(struct DCL *list)
{
    if (list->tail == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return list->tail->data;
}

int size(struct DCL *list)
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

//-------------Insertions-------------

struct Node *insertFirst(struct DCL *list, int value)
{
    struct Node *newNode = createNode(value);
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
    return list->head;
}

struct Node *insertLast(struct DCL *list, int value)
{
    struct Node *newNode = createNode(value);
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
    return list->head;
}

struct Node *insertAt(struct DCL *list, int position, int value)
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
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    if (temp == list->tail)
    { // inserted at the end
        list->tail = newNode;
    }

    return list->head;
}

//-------------Deletions-------------

struct Node *deleteFirst(struct DCL *list)
{
    if (list->head == NULL)
        return NULL;
    struct Node *temp = list->head;
    if (list->head == list->tail)
    {
        printf("Deleted value : %d\n", temp->data);
        free(temp);
        list->head = list->tail = NULL;
        return NULL;
    }
    printf("Deleted value : %d\n", temp->data);
    list->head = list->head->next;
    list->tail->next = list->head;
    list->head->prev = list->tail;

    free(temp);
    return list->head;
}

struct Node *deleteLast(struct DCL *list)
{
    if (list->head == NULL)
        return NULL;
    struct Node *temp = list->tail;
    if (list->head == list->tail)
    {
        printf("Deleted value : %d\n", temp->data);
        free(temp);
        list->head = list->tail = NULL;
        return NULL;
    }

    printf("Deleted value : %d\n", temp->data);
    list->tail = list->tail->prev;
    list->tail->next = list->head;
    list->head->prev = list->tail;
    free(temp);
    return list->head;
}

struct Node *deleteAt(struct DCL *list, int position)
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
    printf("Deleted: %d\n", toDelete->data);

    temp->next = toDelete->next;
    toDelete->next->prev = temp;

    if (toDelete == list->tail)
        list->tail = temp;

    free(toDelete);
    return list->head;
}

struct Node *deleteKey(struct DCL *list, int deleteData)
{
    if (list->head == NULL)
        return NULL;

    struct Node *temp = list->head;
    do
    {
        if (temp->data == deleteData)
        { // handling edge cases here ....
            if (temp == list->head && temp == list->tail)
            {
                printf("Deleted value: %d\n", temp->data); // single Node condition
                free(temp);
                list->head = list->tail = NULL;
                return NULL;
            }
            else if (temp == list->head)
                return deleteFirst(list); // at the start
            else if (temp == list->tail)
                return deleteLast(list); // at last
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                printf("Deleted value: %d\n", temp->data);
                free(temp);
                return list->head;
            }
        }
        temp = temp->next;
    } while (temp != list->head);

    printf("Node with given data: %d not found\n", deleteData);
    return list->head;
}

//-------------Utilties-------------

struct Node *Update(struct DCL *list, int updateVal, int newData)
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
// mis-conceptions: swapping the head and tail doesn't mean reversed in DDL cuz of next and prev connections
struct Node *Reverse(struct DCL *list)
{
    if (list->head == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }
    struct Node *current = list->head;
    struct Node *temp = NULL;
    do
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != list->head);
    temp = list->head;
    list->head = list->tail;
    list->tail = temp;

    return list->head;
}