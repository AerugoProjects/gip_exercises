#include <stdio.h>
#include <stdlib.h>

// Definieren eines Knotens (node)
struct node
{
  int data;
    // Listeneintrag
  struct node *next;
    // Zeiger auf das nächste Element
};


struct node *head;
  // zeigt auf Beginn der Liste (head)


// Erstellen eines Knotens
struct node *mkNode(int val)
{
  struct node *node = NULL;
  if ( (node = malloc(sizeof(struct node))) != NULL )
  {
    node->data = val;
    node->next = NULL;
    return node;
  }
}


/* // Erzeugen von Listenelementen
struct node *a = mkNode(3)

// Verknüpfen der Elemente: b als Nachfolger von a
a->next = b */


// Liste anzeigen
void printList(void)
{
  struct node *tmp = head;
  while (tmp != NULL)
  {
    printf(" %d",tmp->data);
    tmp = tmp->next;
  }
}


// Einfügen am Listenanfang (VL 16 # 12)
void insertFirst (int val)
{
  struct node *p = mkNode(val);
  p->next = head;
    // p->next zeigt dahin, wo head hinzeigt
  head = p;
    // p wird das neue Ziel vom head-Pointer
}


int main(void)
{
  struct node *head;
  // Einträge für Liste erstellen
  struct node *a = mkNode(8);
  struct node *b = mkNode(3);
  struct node *c = mkNode(5);

  //
  a->next = b;
  b->next = c;
  c->next = NULL;

  printList;

  return 0;
}