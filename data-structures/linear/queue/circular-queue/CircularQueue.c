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

struct node *enqueue(struct SCL *list, int value)
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

struct node *dequeue(struct SCL *list)
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

void isEmpty(struct SCL *list)
{
    if (list->head == NULL)
    {
        printf("True");
        return;
    }
    printf("False");
    return;
}

int main()
{
    struct SCL list = initList();

    enqueue(&list, 10);
    enqueue(&list, 20);
    enqueue(&list, 30);
    display(&list);

    enqueue(&list, 5);
    display(&list);

    enqueue(&list, 2);
    display(&list);
    printf("Front: %d\n", front(&list));
    printf("Back: %d\n", back(&list));   
    printf("Size: %d\n", size(&list));

    dequeue(&list);
    display(&list);
    dequeue(&list);
    display(&list);
    dequeue(&list);
    display(&list);
    isEmpty(&list);

    return 0;
}
