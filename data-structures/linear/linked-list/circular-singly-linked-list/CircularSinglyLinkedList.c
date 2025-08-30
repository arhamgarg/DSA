#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct SCL
{
    struct node *head;
    struct node *tail;
};

struct SCL initList()
{
    struct SCL list = {NULL, NULL};
    return list;
}

struct node *createNode(int value)
{
    struct node *new_Node = (struct node *)malloc(sizeof(struct node));
    new_Node->data = value;
    new_Node->next = NULL;
    return new_Node;
}

struct node *insert_First(struct SCL *list, int value)
{
    struct node *new_Node = createNode(value);
    if (list->head == NULL)
    {
        list->head = list->tail = new_Node;
        new_Node->next = new_Node;
    }
    else
    {
        new_Node->next = list->head;
        list->tail->next = new_Node;
        list->head = new_Node;
    }
    return list->head;
}

struct node *insert_Last(struct SCL *list, int value)
{
    struct node *new_Node = createNode(value);
    if (list->head == NULL)
    {
        list->head = list->tail = new_Node;
        new_Node->next = new_Node;
    }
    else
    {
        list->tail->next = new_Node;
        new_Node->next = list->head;
        list->tail = new_Node;
    }
    return list->head;
}

struct node *insert_At(struct SCL *list, int position, int value)
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
    temp->next = new_Node;

    if (temp == list->tail)
    { // inserted at the end
        list->tail = new_Node;
    }

    return list->head;
}

struct node *delete_First(struct SCL *list)
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
    struct node *temp = list->head;
    list->head = list->head->next;
    list->tail->next = list->head;
    printf("Deleted value : %d\n", temp->data);
    free(temp);
    return list->head;
}

struct node *delete_Last(struct SCL *list)
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
    struct node *temp = list->head;
    while (temp->next != list->tail)
        temp = temp->next;
    printf("Deleted value : %d\n", list->tail->data);
    free(list->tail);
    list->tail = temp;
    list->tail->next = list->head;
    return list->head;
}

struct node *delete_At(struct SCL *list, int position)
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
    temp->next = to_Delete->next;

    if (to_Delete == list->tail)
    {
        list->tail = temp;
    }

    printf("Deleted value : %d\n", to_Delete->data);
    free(to_Delete);

    return list->head;
}

void display(struct SCL *list)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *temp = list->head;
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
    struct SCL list = initList();
    //---------------- Test ----------------
    insert_Last(&list, 10);
    insert_Last(&list, 20);
    insert_Last(&list, 30);
    display(&list); // 10 -> 20 -> 30 -> (back to head)

    insert_First(&list, 5);
    display(&list); // 5 -> 10 -> 20 -> 30 -> (back to head)

    insert_At(&list, 2, 15);
    display(&list); // 5 -> 10 -> 15 -> 20 -> 30 -> (back to head)

    printf("Front: %d\n", front(&list)); // 5
    printf("Back: %d\n", back(&list));   // 30
    printf("Size: %d\n", size(&list));   // 5

    delete_First(&list);
    display(&list); // 10 -> 15 -> 20 -> 30 -> (back to head)

    delete_Last(&list);
    display(&list); // 10 -> 15 -> 20 -> (back to head)

    delete_At(&list, 1);
    display(&list); // 10 -> 20 -> (back to head)

    return 0;
}
