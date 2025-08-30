#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *nextNode;
} Node;

Node *createNode(int val, Node *next)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->value = val;
    newNode->nextNode = next;
    return newNode;
}

int getValue(Node *node)
{
    return node->value;
}

Node *getNextNode(Node *node)
{
    return node->nextNode;
}

void setNextNode(Node *node, Node *next)
{
    node->nextNode = next;
}
