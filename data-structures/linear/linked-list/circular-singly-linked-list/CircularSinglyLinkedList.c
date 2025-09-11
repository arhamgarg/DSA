#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct SinglyCircularLinkedList {
  struct Node *head;
  struct Node *tail;
  int size;
};

struct SinglyCircularLinkedList initList() {
  struct SinglyCircularLinkedList list = {NULL, NULL, 0};
  return list;
}

struct Node *createNode(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

void isEmpty(struct SinglyCircularLinkedList *list) {
  printf("List %s empty\n", list->head ? "isn't" : "is");
}

void traverse(struct SinglyCircularLinkedList *list) {
  if (list->head == NULL) {
    printf("Empty\n");
    return;
  }
  struct Node *tempNode = list->head;
  do {
    printf("%d -> ", tempNode->data);
    tempNode = tempNode->next;
  } while (tempNode != list->head);
  printf("(back to head)\n");
}
int front(struct SinglyCircularLinkedList *list) {
  if (list->head == NULL) {
    printf("List empty\n");
    return -1;
  }
  return list->head->data;
}

int back(struct SinglyCircularLinkedList *list) {
  if (list->tail == NULL) {
    printf("List empty\n");
    return -1;
  }
  return list->tail->data;
}

int size(struct SinglyCircularLinkedList *list) { return list->size; }

struct Node *search(struct SinglyCircularLinkedList *list, int searchData) {
  if (list->head == NULL) {
    printf("Empty\n");
    return NULL;
  }
  int pos = 0;
  struct Node *tempNode = list->head;
  do {
    if (tempNode->data == searchData) {
      printf("Data %d found at position %d\n", tempNode->data, pos);
      return tempNode;
    }
    pos++;
    tempNode = tempNode->next;
  } while (tempNode != list->head);
  printf("Data %d not found\n", searchData);
  return NULL;
}

struct Node *insertFirst(struct SinglyCircularLinkedList *list, int value) {
  struct Node *newNode = createNode(value);
  if (list->head == NULL) {
    list->head = list->tail = newNode;
    newNode->next = newNode;
  } else {
    newNode->next = list->head;
    list->tail->next = newNode;
    list->head = newNode;
  }
  list->size++;
  return list->head;
}

struct Node *insertLast(struct SinglyCircularLinkedList *list, int value) {
  struct Node *newNode = createNode(value);
  if (list->head == NULL) {
    list->head = list->tail = newNode;
    newNode->next = newNode;
  } else {
    list->tail->next = newNode;
    newNode->next = list->head;
    list->tail = newNode;
  }
  list->size++;
  return list->head;
}

struct Node *insertAt(struct SinglyCircularLinkedList *list, int position,
                      int value) {
  if (position < 0 || position > list->size) {
    printf("Invalid position\n");
    return list->head;
  }
  if (position == 0) {
    return insertFirst(list, value);
  }
  if (position == list->size) {
    return insertLast(list, value);
  }
  struct Node *tempNode = list->head;
  for (int i = 0; i < position - 1; i++) {
    tempNode = tempNode->next;
  }
  struct Node *newNode = createNode(value);
  newNode->next = tempNode->next;
  tempNode->next = newNode;
  list->size++;
  return list->head;
}

struct Node *deleteFirst(struct SinglyCircularLinkedList *list) {
  if (list->head == NULL)
    return NULL;
  if (list->head == list->tail) {
    printf("Deleted value : %d\n", list->head->data);
    free(list->head);
    list->head = list->tail = NULL;
    list->size--;
    return NULL;
  }
  struct Node *tempNode = list->head;
  list->head = list->head->next;
  list->tail->next = list->head;
  printf("Deleted value : %d\n", tempNode->data);
  free(tempNode);
  list->size--;
  return list->head;
}

struct Node *deleteLast(struct SinglyCircularLinkedList *list) {
  if (list->head == NULL)
    return NULL;
  if (list->head == list->tail) {
    printf("Deleted value : %d\n", list->head->data);
    free(list->head);
    list->head = list->tail = NULL;
    return NULL;
  }
  struct Node *tempNode = list->head;
  while (tempNode->next != list->tail)
    tempNode = tempNode->next;
  printf("Deleted value : %d\n", list->tail->data);
  free(list->tail);
  list->tail = tempNode;
  list->tail->next = list->head;
  list->size--;
  return list->head;
}

struct Node *deleteAt(struct SinglyCircularLinkedList *list, int position) {
  if (list->head == NULL)
    return NULL;
  if (position < 0 || position >= list->size) {
    printf("Invalid position\n");
    return list->head;
  }
  if (position == 0)
    return deleteFirst(list);

  struct Node *tempNode = list->head;
  int count = 0;
  while (count < position - 1 && tempNode->next != list->head) {
    tempNode = tempNode->next;
    count++;
  }

  struct Node *toDelete = tempNode->next;
  tempNode->next = toDelete->next;

  if (toDelete == list->tail) {
    list->tail = tempNode;
  }

  printf("Deleted value : %d\n", toDelete->data);
  free(toDelete);
  list->size--;
  return list->head;
}

struct Node *update(struct SinglyCircularLinkedList *list, int updateVal,
                    int newData) {
  if (list->head == NULL) {
    printf("Empty List\n");
    return NULL;
  }

  struct Node *tempNode = list->head;
  do {
    if (tempNode->data == updateVal) {
      tempNode->data = newData;
      printf("Node updated: %d -> %d\n", updateVal, newData);
      return list->head;
    }
    tempNode = tempNode->next;
  } while (tempNode != list->head);
  printf("Node with given data: %d not found\n", updateVal);
  return list->head;
}
