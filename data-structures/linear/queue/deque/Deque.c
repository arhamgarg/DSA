#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct Deque
{
    struct node *Front;
    struct node *Rear;
};

struct Deque initList()
{
    struct Deque dq = {NULL, NULL};
    return dq;
}

struct node *createNode(int value)
{
    struct node *new_Node = (struct node *)malloc(sizeof(struct node));
    new_Node->data = value;
    new_Node->next = new_Node->prev = NULL;
    return new_Node;
}

struct node *insertFront(struct Deque *dq, int value)
{
    struct node *new_Node = createNode(value);
    if (dq->Front == NULL)
        dq->Front = dq->Rear = new_Node;
    else
    {
        new_Node->next = dq->Front;
        dq->Front->prev = new_Node;
        dq->Front = new_Node;
    }
    return new_Node;
}

struct node *insertRear(struct Deque *dq, int value)
{
    struct node *new_Node = createNode(value);
    if (dq->Front == NULL)
        dq->Front = dq->Rear = new_Node;
    else
    {
        dq->Rear->next = new_Node;
        new_Node->prev = dq->Rear;
        dq->Rear = new_Node;
    }
    return new_Node;
}

struct node *deleteFront(struct Deque *dq)
{
    if (dq->Front == NULL)
    {
        printf("Deque is empty\n");
        return NULL;
    }

    struct node *temp = dq->Front;
    dq->Front = dq->Front->next;

    if (dq->Front != NULL)
    {
        printf("Deleted value: %d\n", temp->data);
        dq->Front->prev = NULL;
    }
    free(temp);
    return dq->Front;
}

struct node *deleteRear(struct Deque *dq)
{
    if (dq->Front == NULL)
    {
        printf("Deque is empty\n");
        return NULL;
    }

    struct node *temp = dq->Rear;
    dq->Rear = dq->Rear->prev;

    if (dq->Rear != NULL)
    {
        printf("Deleted value: %d\n", temp->data);
        dq->Rear->next = NULL;
    }
    free(temp);
    return dq->Rear;
}

int size(struct Deque *dq)
{
    int count = 0;
    struct node *temp = dq->Front;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int getfront(struct Deque *dq)
{
    if (dq->Front == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return dq->Front->data;
}

int getRear(struct Deque *dq)
{
    if (dq->Rear == NULL)
    {
        printf("List empty\n");
        return -1;
    }
    return dq->Rear->data;
}

void displayForward(struct Deque *dq)
{
    struct node *temp = dq->Front;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayBackward(struct Deque *dq)
{
    struct node *temp = dq->Rear;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main()
{
    struct Deque dq = initList();
    //---------------- Test ----------------
    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    insertRear(&dq, 30);

    printf("Deque Forward: ");
    displayForward(&dq);

    printf("Deque Backward: ");
    displayBackward(&dq);

    printf("Front element: %d\n", getfront(&dq));
    printf("Rear element: %d\n", getRear(&dq));
    printf("Size: %d\n", size(&dq));

    deleteFront(&dq);
    deleteRear(&dq);

    printf("Deque after deletions: ");
    displayForward(&dq);

    return 0;
}
