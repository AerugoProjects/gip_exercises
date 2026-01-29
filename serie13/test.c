#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int value;
  struct Node *parent;
}Node;

struct Node *mkNode(int val)
{
  Node *node = NULL;
  node = malloc(sizeof(Node));
  node->value = val;
  node->parent = NULL;
}

Node *movesHEAD = NULL;
Node *deadEndsHEAD = NULL;


struct Node *reverse()
{
  Node *reverseHEAD = NULL;
  Node *p = deadEndsHEAD;
  while (p != 0)
  {
    Node *n = mkNode (p->value);
    n->parent = reverseHEAD;
    reverseHEAD = n;
    p = p->parent;
    return reverseHEAD;
  }
}


void insertFirst (int val)
{
  Node *p = mkNode(val);
  p->parent = movesHEAD;
  movesHEAD = p;
}


struct node *search (int val, Node *HEAD)
{
  Node *p = HEAD;
  while (p != 0 && p->value != val)
    p = p->parent;
  return p;
};
