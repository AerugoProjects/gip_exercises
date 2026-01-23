#include <stdio.h>
#include <stdlib.h>


/* Datentyp Node erstellen: Datentyp für die einzelnen Listen-
elemente mit einem Wert val und dem Zeiger zum nächsten Ele-
ment *next */
typedef struct Node
{
  int value;
  struct Node *next;
}Node;


/* Datentyp für eine Liste erstellen */
typedef struct
{
  Node *head; // Pointer to the head
  Node *tail; // Pointer to the tail
  int size;   // Size of the list
} List;


/* Erstellen einer Liste */
List *createList()
{
  List *list = malloc(sizeof(List));
    // reserve memory for the list
  list->head = NULL;
  list->tail = NULL;
    // head-pointer and tail-pointer are set to NULL
  list->size = 0;
    // List has no entrys
  
  return list;
}


void insertSorted (List *list, int val);
void addSecond (List *list, int value);
void printList(List *list);;
void addFirstEntry (List *list, int value);



/////   -----   /////

int main (void)
{
  // create a list
  List *listA = createList();
  addFirstEntry(listA,1);
  addSecond(listA, 9);
  addSecond(listA, 7);
  addSecond(listA, 5);
  addSecond(listA, 3);
  addSecond(listA, 2);

  printf("Liste A: ");
  printList(listA);

  printf("\nEinzufügendes Element: 4");
  printf("\n neue Liste A: ");
  insertSorted(listA, 4);

  printList(listA);


  return 0;
}

/////   -----   /////



void insertSorted (List *list, int val)
{
  Node *currentNode = list->head;
  while (currentNode->next->value < val)
    currentNode = currentNode->next;
  
  Node *newNode = malloc(sizeof(Node));
  newNode->value = val;
  newNode->next = currentNode->next;
  currentNode->next = newNode;
}


/* Add entry at the begin of the list*/
void addSecond (List *list, int value)
{
  Node *newNode = malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = list->head->next;
    /* next-pointer of newNode shows at the same node like
    the head-pointer of the list */
  list->head->next = newNode;
    /* head-pointer shows at the new node*/
  list->size++;
}


void printList (List *list)
{
  Node *currentNode = list->head;

  while (currentNode != NULL)
  {
    printf("%d ", currentNode->value);
    currentNode = currentNode->next;
  }
}


void addFirstEntry (List *list, int value)
{
  Node *newNode = malloc(sizeof(Node));
  newNode->value = value;
  list->head = newNode;
  newNode->next = list->tail;
  list->size++;
}