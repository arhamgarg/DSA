#include <stdio.h>
#include <stdlib.h>

// ---------------- Node Definition ----------------
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// ---------------- List Definition ----------------
struct DLL
{
    struct node *head;
    struct node *tail;
    int count;
};

// ---------------- Initialization ----------------
struct DLL initList()
{
    struct DLL list = {NULL, NULL, 0};
    return list;
}

// ---------------- Node Creation ----------------
struct node *createNode(int value)
{
    struct node *new_Node = (struct node *)malloc(sizeof(struct node));
    new_Node->data = value;
    new_Node->next = NULL;
    new_Node->prev = NULL;
    return new_Node;
}

// ---------------- Insert Operations ----------------
struct node *insertFirst(struct DLL *list, int value)
{
    struct node *new_Node = createNode(value);

    if (list->head == NULL)
    {
        list->head = list->tail = new_Node;
    }
    else
    {
        new_Node->next = list->head;
        list->head->prev = new_Node;
        list->head = new_Node;
    }
    list->count++;
    return new_Node;
}

struct node *insertLast(struct DLL *list, int value)
{
    struct node *new_Node = createNode(value);

    if (list->tail == NULL)
    {
        list->head = list->tail = new_Node;
    }
    else
    {
        new_Node->prev = list->tail;
        list->tail->next = new_Node;
        list->tail = new_Node;
    }
    list->count++;
    return new_Node;
}

struct node *insertAt(struct DLL *list, int position, int value)
{
    if (position < 0 || position > list->count)
    {
        printf("Invalid position\n");
        return NULL;
    }

    if (position == 0)
        return insertFirst(list, value);
    if (position == list->count)
        return insertLast(list, value);

    struct node *temp = list->head;
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }

    struct node *new_Node = createNode(value);
    new_Node->next = temp->next;
    new_Node->prev = temp;
    temp->next->prev = new_Node;
    temp->next = new_Node;

    list->count++;
    return new_Node;
}

// ---------------- Delete Operations ----------------
struct node *deleteFirst(struct DLL *list)
{
    if (list->head == NULL)
        return NULL;

    struct node *temp = list->head;
    if (list->head == list->tail)
    {
        list->head = list->tail = NULL;
    }
    else
    {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    printf("Deleted value: %d\n", temp->data);
    free(temp);
    list->count--;
    return list->head;
}

struct node *deleteLast(struct DLL *list)
{
    if (list->tail == NULL)
        return NULL;

    struct node *temp = list->tail;
    if (list->head == list->tail)
    {
        list->head = list->tail = NULL;
    }
    else
    {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    printf("Deleted value: %d\n", temp->data);
    free(temp);
    list->count--;
    return list->tail;
}

struct node *deleteAt(struct DLL *list, int position)
{
    if (position < 0 || position >= list->count)
    {
        printf("Invalid position\n");
        return NULL;
    }

    if (position == 0)
        return deleteFirst(list);
    if (position == list->count - 1)
        return deleteLast(list);

    struct node *temp = list->head;
    for (int i = 0; i < position; i++)
    {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted value: %d\n", temp->data);
    free(temp);
    list->count--;
    return list->head;
}

struct node *deleteKey(struct DLL *list, int delete_data)
{
    if (list->head == NULL)
        return NULL;

    if (list->head->data == delete_data)
    {
        return deleteFirst(list);
    }

    struct node *temp = list->head;
    while (temp != NULL && temp->data != delete_data)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Data not found\n");
        return NULL;
    }

    if (temp == list->tail)
    {
        return deleteLast(list);
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted value: %d\n", temp->data);
    free(temp);
    list->count--;
    return list->head;
}

// ---------------- Search ----------------
struct node *search(struct DLL *list, int value)
{
    struct node *temp = list->head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// ---------------- Update ----------------
struct node *update(struct DLL *list, int old_value, int new_value)
{
    struct node *temp = search(list, old_value);
    if (temp != NULL)
    {
        temp->data = new_value;
        return temp;
    }
    printf("Value not found\n");
    return NULL;
}

// ---------------- Reverse ----------------
struct node *Reverse(struct DLL *list)
{
    struct node *curr = list->head;
    struct node *temp = NULL;

    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
    {
        list->head = temp->prev;
    }

    // swap head and tail
    temp = list->head;
    list->head = list->tail;
    list->tail = temp;

    return list->head;
}

// ---------------- Copy ----------------
struct node *Copy(struct DLL *list, struct DLL *copy_list)
{
    struct node *temp = list->head;
    while (temp != NULL)
    {
        insertLast(copy_list, temp->data);
        temp = temp->next;
    }
    return copy_list->head;
}

// ---------------- Utilities ----------------
void traverseForward(struct DLL *list)
{
    struct node *temp = list->head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traverseBackward(struct DLL *list)
{
    struct node *temp = list->tail;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void isEmpty(struct DLL *list)
{
    if (list->head == NULL)
        printf("List is empty\n");
    else
        printf("List isn't empty\n");
}

int size(struct DLL *list)
{
    return list->count;
}

// ---------------- Main ----------------
int main()
{
    struct DLL list = initList();

    // Inserts
    insertFirst(&list, 10);
    insertFirst(&list, 20);
    insertLast(&list, 30);
    insertAt(&list, 1, 15);

    printf("Forward traversal: ");
    traverseForward(&list);
    printf("Backward traversal: ");
    traverseBackward(&list);

    // Deletes
    deleteFirst(&list);
    deleteLast(&list);
    deleteAt(&list, 1);
    deleteKey(&list, 10);

    printf("After deletions (forward): ");
    traverseForward(&list);

    // Search & Update
    insertLast(&list, 40);
    insertLast(&list, 50);
    struct node *found = search(&list, 40);
    if (found)
        printf("Found: %d\n", found->data);
    update(&list, 50, 60);

    printf("After update (forward): ");
    traverseForward(&list);

    // Reverse
    Reverse(&list);
    printf("After reverse (forward): ");
    traverseForward(&list);

    // Copy
    struct DLL copyList = initList();
    Copy(&list, &copyList);
    printf("Copied list (forward): ");
    traverseForward(&copyList);

    // Utilities
    isEmpty(&list);
    printf("Size of list: %d\n", size(&list));

    return 0;
}
