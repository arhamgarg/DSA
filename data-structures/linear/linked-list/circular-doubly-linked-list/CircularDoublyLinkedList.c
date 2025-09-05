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
//-------------Core-operations-------------

struct node *createNode(int value)
{
    struct node *new_Node = (struct node *)malloc(sizeof(struct node));
    new_Node->data = value;
    new_Node->next = new_Node->prev = NULL;
    return new_Node;
}

void TraverseForward(struct DCL *list)
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

void TraverseBackward(struct DCL *list)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *temp = list->tail;
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

void Search(struct DCL *list, int search_data)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    int pos = 0;
    struct node *temp = list->head;
    do
    {
        if (temp->data == search_data)
        {
            printf("Data %d found at position %d\n", temp->data, pos);
            return;
        }
        pos++;
        temp = temp->next;
    } while (temp != list->head);
    printf("Data %d not found\n", search_data);
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

//-------------Insertions-------------

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

//-------------Deletions-------------

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

struct node *deleteKey(struct DCL *list, int delete_data)
{
    if (list->head == NULL)
        return NULL;

    struct node *temp = list->head;
    do
    {
        if (temp->data == delete_data)
        { // handling edge cases here ....
            if (temp == list->head && temp == list->tail)
            {
                printf("Deleted value: %d\n", temp->data); // single node condition
                free(temp);
                list->head = list->tail = NULL;
                return NULL;
            }
            else if (temp == list->head)
                return delete_First(list); // at the start
            else if (temp == list->tail)
                return delete_Last(list); // at last
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

    printf("Node with given data: %d not found\n", delete_data);
    return list->head;
}

//-------------Utilties-------------

struct node *Update(struct DCL *list, int update_val, int new_data)
{
    if (list->head == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }

    struct node *temp = list->head;
    do
    {
        if (temp->data == update_val)
        {
            temp->data = new_data;
            printf("Node updated: %d -> %d\n", update_val, new_data);
            return list->head;
        }
        temp = temp->next;
    } while (temp != list->head);
    printf("Node with given data: %d not found\n", update_val);
    return list->head;
}
// mis-conceptions: swapping the head and tail doesn't mean reversed in DDL cuz of next and prev connections
struct node *Reverse(struct DCL *list)
{
    if (list->head == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }
    struct node *current = list->head;
    struct node *temp = NULL;
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

int main()
{
    struct DCL list = initList();

    //---------------- Test ----------------
    insert_Last(&list, 10);
    insert_Last(&list, 20);
    insert_Last(&list, 30);
    TraverseForward(&list);

    insert_First(&list, 5);
    TraverseForward(&list);

    insert_At(&list, 2, 15);
    TraverseForward(&list);

    printf("Front: %d\n", front(&list));
    printf("Back: %d\n", back(&list));
    printf("Size: %d\n", size(&list));

    delete_First(&list);
    TraverseForward(&list);

    delete_Last(&list);
    TraverseForward(&list);

    delete_At(&list, 1);
    TraverseForward(&list);

    // Try delete by key
    deleteKey(&list, 15);
    TraverseForward(&list);

    // Try update
    Update(&list, 20, 200);
    TraverseForward(&list);

    // Try reverse
    Reverse(&list);
    TraverseForward(&list);
    TraverseBackward(&list);

    return 0;
}
