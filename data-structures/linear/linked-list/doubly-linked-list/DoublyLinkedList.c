#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// we can also have tail variable  which can reduce almost all the functions to O(n)
// and they will work similar to head variables
struct node *createNode(int value)
{
    struct node *new_Node = (struct node *)malloc(sizeof(struct node));
    new_Node->data = value;
    new_Node->next = NULL;
    new_Node->prev = NULL;
    return new_Node;
}

struct node *insertFirst(struct node *head, int value)
{
    struct node *new_Node = createNode(value);
    new_Node->next = head;
    head->prev = new_Node;
    return new_Node;
}

struct node *insertLast(struct node *head, int value)
{
    struct node *new_Node = createNode(value);
    if (head == NULL)
        return new_Node;

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_Node;
    new_Node->prev = temp;
    return head;
}

struct node *insertAt(struct node *head, int position, int value)
{
    if (position == 0)
        return insertFirst(head, value);

    struct node *temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    struct node *new_Node = createNode(value);
    new_Node->next = temp->next;
    temp->next = new_Node;
    new_Node->prev = temp;
    return head;
}

struct node *deleteFirst(struct node *head)
{
    if (head == NULL)
        return NULL;

    struct node *temp = head;
    head = head->next;

    if (head != NULL)
    {
        printf("Deleted value: %d\n", temp->data);
        head->prev = NULL;
    }
    free(temp);
    return head;
}

struct node *deleteLast(struct node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        printf("Deleted value: %d\n", head->next->data);
        free(head);
        return NULL;
    }

    struct node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    printf("Deleted value: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct node *deleteAt(struct node *head, int position)
{
    if (head == NULL)
        return NULL;
    if (position == 0)
        return deleteFirst(head);

    struct node *temp = head;
    for (int i = 0; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;

    printf("Deleted value: %d\n", temp->data);
    free(temp);
    return head;
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

void displayForward(struct node *head)
{
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void displayBackward(struct node *head)
{
    if (head == NULL)
    {
        printf("NULL\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next; // move to tail

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    //---------------- Test ----------------
    head = insertLast(head, 10);
    head = insertLast(head, 20);
    head = insertLast(head, 30);
    displayForward(head); // 10 -> 20 -> 30 -> NULL

    head = insertFirst(head, 5);
    displayForward(head); // 5 -> 10 -> 20 -> 30 -> NULL

    head = insertAt(head, 2, 15);
    displayForward(head); // 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    head = deleteFirst(head);
    displayForward(head); // 10 -> 15 -> 20 -> 30 -> NULL

    head = deleteLast(head);
    displayForward(head); // 10 -> 15 -> 20 -> NULL

    head = deleteAt(head, 1);
    displayForward(head); // 10 -> 20 -> NULL

    printf("Backward traversal: ");
    displayBackward(head); // 20 -> 10 -> NULL

    return 0;
}
