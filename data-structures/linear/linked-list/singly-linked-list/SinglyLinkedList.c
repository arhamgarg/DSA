#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
// we can also have tail variable  which can reduce almost all the functions to O(n)
// and they will work similar to head variables

//--------------Core operations--------------

struct node *createNode(int value)
{
    struct node *new_Node = (struct node *)malloc(sizeof(struct node));
    new_Node->data = value;
    new_Node->next = NULL;
    return new_Node;
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

void Traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct node *Update(struct node *head, int update_val, int new_data)
{
    struct node *temp = head;
    while (temp != NULL && temp->data != update_val)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Node with given data: %d not found\n", update_val);
        return head;
    }
    temp->data = new_data;
    return head;
}

void Search(struct node *head, int search_data)
{
    struct node *temp = head;
    int pos = 0;
    while (temp != NULL)
    {
        if (temp->data == search_data)
        {
            printf("Data %d found at position %d\n", temp->data, pos);
            return; // stop at first match
        }
        temp = temp->next;
        pos++;
    }
    printf("Data %d not found\n", search_data);
}

int getAtIndex(struct node *head, int index)
{
    int index_counter = 0;
    while (head != NULL)
    {
        if (index == index_counter)
            return head->data;
        head = head->next;
        index_counter++;
    }
    printf("Index out of range\n");
    return -1;
}

void isEmpty(struct node *head)
{
    printf("List %s empty\n", head ? "isn't" : "is");
}
//--------------Insertion--------------

struct node *insertFirst(struct node *head, int value)
{
    struct node *new_Node = createNode(value);
    new_Node->next = head;
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
    return head;
}

struct node *insertAfter(struct node *head, int node_Data, int data)
{
    struct node *new_Node = createNode(data);
    if (head == NULL)
    {
        return new_Node;
    }
    struct node *temp = head;
    while (temp != NULL && temp->data != node_Data)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node with given data: %d nor found", node_Data);
        return head;
    }
    new_Node->next = temp->next;
    temp->next = new_Node;
    return head;
}

//--------------Deletions--------------

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
    struct node *temp = head;
    head = head->next;
    printf("Deleted value: %d\n", temp->data);
    free(temp);
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

    struct node *to_Delete = temp->next;
    temp->next = temp->next->next;
    printf("Deleted value: %d\n", to_Delete->data);
    free(to_Delete);
    return head;
}

struct node *deleteKey(struct node *head, int delete_data)
{
    if (head == NULL)
        return NULL;
    if (head->data == delete_data)
    {
        struct node *temp = head;
        head = head->next;
        printf("Deleted value: %d\n", temp->data);
        free(temp);
        return head;
    }

    struct node *prev = head;
    struct node *to_Delete = head->next;

    while (to_Delete != NULL && to_Delete->data != delete_data)
    {
        prev = to_Delete;
        to_Delete = to_Delete->next;
    }
    if (to_Delete == NULL)
    {
        printf("Node with given data: %d not found\n", delete_data);
        return head;
    }
    prev->next = to_Delete->next;
    printf("Deleted value: %d\n", to_Delete->data);
    free(to_Delete);
    return head;
}

//--------------Utilities--------------

struct node *Reverse(struct node *head)
{
    if (head == NULL)
        return NULL;
    struct node *prev_Node = NULL;
    struct node *current_Node = head;
    struct node *next_Node = NULL;

    while (current_Node != NULL)
    {
        next_Node = current_Node->next;
        current_Node->next = prev_Node;
        prev_Node = current_Node;
        current_Node = next_Node;
    }
    head = prev_Node;
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

struct node *Copy(struct node *head, struct node *head_Copy)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        head_Copy = insertLast(head_Copy, temp->data);
        temp = temp->next;
    }
    return head_Copy;
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

int main()
{
    struct node *head = NULL;

    head = insertLast(head, 10);
    head = insertLast(head, 20);
    head = insertLast(head, 30);
    Traverse(head); // 10 -> 20 -> 30 -> NULL

    head = insertFirst(head, 5);
    Traverse(head); // 5 -> 10 -> 20 -> 30 -> NULL

    head = insertAt(head, 2, 15);
    Traverse(head); // 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    head = insertAfter(head, 15, 18);
    Traverse(head); // 5 -> 10 -> 15 -> 18 -> 20 -> 30 -> NULL

    printf("Front: %d\n", front(head));
    printf("Last: %d\n", last(head));
    printf("Size: %d\n", size(head));
    printf("Get(2): %d\n", getAtIndex(head, 2));

    head = Update(head, 15, 16);
    Traverse(head); // 5 -> 10 -> 16 -> 18 -> 20 -> 30 -> NULL

    head = deleteFirst(head);
    Traverse(head); // 10 -> 16 -> 18 -> 20 -> 30 -> NULL

    head = deleteLast(head);
    Traverse(head); // 10 -> 16 -> 18 -> 20 -> NULL

    head = deleteAt(head, 1);
    Traverse(head); // 10 -> 18 -> 20 -> NULL

    head = deleteKey(head, 18);
    Traverse(head); // 10 -> 20 -> NULL

    head = Reverse(head);
    Traverse(head); // 20 -> 10 -> NULL

    head = insertLast(head, 25);
    head = insertLast(head, 35);
    Traverse(head);
    findMiddle(head); // prints "The middle value is: 10" or "25"

    return 0;
}
