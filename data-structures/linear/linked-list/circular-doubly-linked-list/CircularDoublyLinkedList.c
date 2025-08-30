#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct DCL
{
    struct node *head;
    struct node *tail;
};

struct DCL initList()
{
    struct DCL list = {NULL, NULL};
    return list;
}

struct node *createNode(int value)
{
    struct node *new_Node = (struct node *)malloc(sizeof(struct node));
    new_Node->data = value;
    new_Node->next = new_Node->prev = NULL;
    return new_Node;
}

struct node *insert_First(struct DCL *list, int value)
{
    struct node *new_Node = createNode(value);
    if (list->head == NULL)
    {
        list->head = list->tail = new_Node;
        new_Node->next = new_Node->prev = new_Node;
    }
    else
    {
        new_Node->next = list->head;
        new_Node->prev = list->tail;
        list->tail->next = new_Node;
        list->head->prev = new_Node;
        list->head = new_Node;
    }
    return list->head;
}

struct node *insert_Last(struct DCL *list, int value)
{
    struct node *new_Node = createNode(value);
    if (list->head == NULL)
    {
        list->head = list->tail = new_Node;
        new_Node->next = new_Node->prev = new_Node;
    }
    else
    {
        new_Node->prev = list->tail;
        new_Node->next = list->head;
        list->tail->next = new_Node;
        list->head->prev = new_Node;
        list->tail = new_Node;
    }
    return list->head;
}

struct node *insert_At(struct DCL *list, int position, int value)
{
    if (position == 0)
    {
        return insert_First(list, value);
    }

    struct node *temp = list->head;
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

    struct node *new_Node = createNode(value);
    new_Node->next = temp->next;
    new_Node->prev = temp;
    temp->next->prev = new_Node;
    temp->next = new_Node;

    if (temp == list->tail)
    { // inserted at the end
        list->tail = new_Node;
    }

    return list->head;
}

struct node *delete_First(struct DCL *list)
{
    if (list->head == NULL)
        return NULL;
    struct node *temp = list->head;
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

struct node *delete_Last(struct DCL *list)
{
    if (list->head == NULL)
        return NULL;
    struct node *temp = list->tail;
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

struct node *delete_At(struct DCL *list, int position)
{
    if (list->head == NULL)
        return NULL;
    if (position == 0)
        return delete_First(list);

    struct node *temp = list->head;
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

    struct node *to_Delete = temp->next;
    printf("Deleted: %d\n", to_Delete->data);

    temp->next = to_Delete->next;
    to_Delete->next->prev = temp;

    if (to_Delete == list->tail)
        list->tail = temp;

    free(to_Delete);
    return list->head;
}

void display(struct DCL *list)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *temp = list->head;
    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(back to head)\n");
}
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
    struct node *temp = list->head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != list->head);
    return count;
}

int main()
{
    struct DCL list = initList();
    //---------------- Test ----------------
    insert_Last(&list, 10);
    insert_Last(&list, 20);
    insert_Last(&list, 30);
    display(&list);

    insert_First(&list, 5);
    display(&list);

    insert_At(&list, 2, 15);
    display(&list);

    printf("Front: %d\n", front(&list));
    printf("Back: %d\n", back(&list));
    printf("Size: %d\n", size(&list));

    delete_First(&list);
    display(&list);

    delete_Last(&list);
    display(&list);

    delete_At(&list, 1);
    display(&list);

    return 0;
}
