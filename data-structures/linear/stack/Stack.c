#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct node *push(struct node *head, int value)
{
    struct node *new_Node = createNode(value);
    new_Node->next = head;
    return new_Node;
}

struct node *pop(struct node *head)
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

int top(struct node *head)
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

int main()
{
    struct node *head = NULL;
    //---------------- Test ----------------
    head = push(head, 10);
    head = push(head, 20);
    head = push(head, 30);
    display(head); // 10 -> 20 -> 30 -> NULL

    printf("top: %d\n", top(head));
    printf("Size: %d\n", size(head));

    head = pop(head);
    display(head); // 10 -> 15 -> 20 -> 30 -> NULL
    isEmpty(head);
    return 0;
}
