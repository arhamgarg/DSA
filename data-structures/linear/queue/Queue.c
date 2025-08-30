#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
// we can also have tail variable  which can reduce almost all the functions to O(n)
// and they will work similar to head variables
struct node *createNode(int value)
{
    struct node *new_Node = (struct node *)malloc(sizeof(struct node));
    new_Node->data = value;
    new_Node->next = NULL;
    return new_Node;
}

struct node *enqueue(struct node *head, int value)
{
    struct node *new_Node = createNode(value);
    if (head == NULL)
        return new_Node;
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_Node;
    return head;
}

struct node *dequeue(struct node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        printf("Deleted value: %d\n", head->data);
        free(head);
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
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

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void isEmpty(struct node *head)
{
    if (head == NULL)
    {
        printf("True");
        return;
    }
    printf("False");
    return;
}
int main()
{
    struct node *head = NULL;
    //---------------- Test ----------------
    head = enqueue(head, 10);
    head = enqueue(head, 20);
    head = enqueue(head, 30);
    head = enqueue(head, 5);
    head = enqueue(head, 2);
    display(head);

    printf("Front: %d\n", front(head));
    printf("Size: %d\n", size(head));

    head = dequeue(head);
    display(head);

    head = dequeue(head);
    display(head);

    head = dequeue(head);
    display(head);
    isEmpty(head);

    return 0;
}
