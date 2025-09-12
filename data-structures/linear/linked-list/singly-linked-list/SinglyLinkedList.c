#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *createNode(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

int getSize(struct Node *head) {
  int count = 0;
  while (head != NULL) {
    count++;
    head = head->next;
  }
  return count;
}

void traverse(struct Node *head) {
  while (head != NULL) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

struct Node *update(struct Node *head, int updateValue, int newData) {
  struct Node *tempNode = head;
  while (tempNode != NULL && tempNode->data != updateValue)
    tempNode = tempNode->next;

  if (tempNode == NULL) {
    printf("Node with given data: %d not found\n", updateValue);
    return head;
  }
  tempNode->data = newData;
  return head;
}

void search(struct Node *head, int searchData) {
  struct Node *tempNode = head;
  int pos = 0;
  while (tempNode != NULL) {
    if (tempNode->data == searchData) {
      printf("Data %d found at position %d\n", tempNode->data, pos);
      return;
    }
    tempNode = tempNode->next;
    pos++;
  }
  printf("Data %d not found\n", searchData);
}

int getAtIndex(struct Node *head, int index) {
  int indexCounter = 0;
  while (head != NULL) {
    if (index == indexCounter)
      return head->data;
    head = head->next;
    indexCounter++;
  }
  printf("Index out of range\n");
  return -1;
}

void isEmpty(struct Node *head) {
  printf("List %s empty\n", head ? "isn't" : "is");
}

struct Node *insertFirst(struct Node *head, int value) {
  struct Node *newNode = createNode(value);
  newNode->next = head;
  head = newNode;
  return head;
}

struct Node *insertLast(struct Node *head, int value) {
  struct Node *newNode = createNode(value);
  if (head == NULL)
    return newNode;
  struct Node *tempNode = head;
  while (tempNode->next != NULL)
    tempNode = tempNode->next;
  tempNode->next = newNode;
  return head;
}

struct Node *insertAt(struct Node *head, int position, int value) {
  if (position == 0)
    return insertFirst(head, value);

  struct Node *tempNode = head;
  for (int i = 0; i < position - 1 && tempNode != NULL; i++)
    tempNode = tempNode->next;

  if (tempNode == NULL) {
    printf("Position out of range\n");
    return head;
  }

  struct Node *newNode = createNode(value);
  newNode->next = tempNode->next;
  tempNode->next = newNode;
  return head;
}

struct Node *insertAfter(struct Node *head, int NodeData, int data) {
  struct Node *newNode = createNode(data);
  if (head == NULL) {
    return newNode;
  }
  struct Node *tempNode = head;
  while (tempNode != NULL && tempNode->data != NodeData) {
    tempNode = tempNode->next;
  }
  if (tempNode == NULL) {
    printf("Node with given data: %d not found\n", NodeData);
    return head;
  }
  newNode->next = tempNode->next;
  tempNode->next = newNode;
  return head;
}

struct Node *deleteFirst(struct Node *head) {
  if (head == NULL)
    return NULL;

  struct Node *tempNode = head;
  head = head->next;
  printf("Deleted value: %d\n", tempNode->data);
  free(tempNode);
  return head;
}

struct Node *deleteLast(struct Node *head) {
  if (head == NULL)
    return NULL;
  if (head->next == NULL) {
    printf("Deleted value: %d\n", head->data);
    free(head);
    return NULL;
  }
  struct Node *tempNode = head;
  while (tempNode->next->next != NULL)
    tempNode = tempNode->next;
  printf("Deleted value: %d\n", tempNode->next->data);
  free(tempNode->next);
  tempNode->next = NULL;
  return head;
}

struct Node *deleteAt(struct Node *head, int position) {
  if (head == NULL)
    return NULL;
  if (position == 0)
    return deleteFirst(head);

  struct Node *tempNode = head;
  for (int i = 0; i < position - 1 && tempNode->next != NULL; i++)
    tempNode = tempNode->next;

  if (tempNode->next == NULL) {
    printf("Position out of range\n");
    return head;
  }

  struct Node *toDelete = tempNode->next;
  tempNode->next = tempNode->next->next;
  printf("Deleted value: %d\n", toDelete->data);
  free(toDelete);
  return head;
}

struct Node *deleteKey(struct Node *head, int deleteData) {
  if (head == NULL)
    return NULL;
  if (head->data == deleteData) {
    struct Node *tempNode = head;
    head = head->next;
    printf("Deleted value: %d\n", tempNode->data);
    free(tempNode);
    return head;
  }

  struct Node *prev = head;
  struct Node *toDelete = head->next;

  while (toDelete != NULL && toDelete->data != deleteData) {
    prev = toDelete;
    toDelete = toDelete->next;
  }
  if (toDelete == NULL) {
    printf("Node with given data: %d not found\n", deleteData);
    return head;
  }
  prev->next = toDelete->next;
  printf("Deleted value: %d\n", toDelete->data);
  free(toDelete);
  return head;
}

struct Node *reverse(struct Node *head) {
  if (head == NULL)
    return NULL;
  struct Node *prevNode = NULL;
  struct Node *currentNode = head;
  struct Node *nextNode = NULL;

  while (currentNode != NULL) {
    nextNode = currentNode->next;
    currentNode->next = prevNode;
    prevNode = currentNode;
    currentNode = nextNode;
  }
  head = prevNode;
  return head;
}

int last(struct Node *head) {
  if (head == NULL) {
    printf("List empty\n");
    return -1;
  }
  while (head->next != NULL)
    head = head->next;
  return head->data;
}

struct Node *copy(struct Node *head, struct Node *headCopy) {
  if (headCopy != NULL) {
    printf("Warning: destination list not empty. Copy may append to existing "
           "list.\n");
  }
  struct Node *tempNode = head;
  while (tempNode != NULL) {
    headCopy = insertLast(headCopy, tempNode->data);
    tempNode = tempNode->next;
  }
  return headCopy;
}

struct Node *findMiddle(struct Node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  struct Node *fast = head;
  struct Node *slow = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
