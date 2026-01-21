/*
In der Vorlesung wurden einfach verkettete Listen als dyna-
mische Datenstruktur vorgestellt. Implementieren Sie für die-
sen Datentyp folgende zusätzliche Funktion in C:

struct node *reverse(), zur Rückgabe einer invertierten Liste
ohne die Liste zu verändern.

Testen Sie die Funktion in einem geeigneten Hauptprogramm!
*/

/*
Quelle: https://de.wikibooks.org/wiki/C-Programmierung:_Verkettete_Listen
*/
#include <stdio.h>
#include <stdlib.h>

struct element
{
    int value;            /* der Wert des Elements          */
    struct element *next; /* Zeiger auf das nächste Element */
};


void printliste(const struct element *e)
{
    for( ; e != NULL ; e = e->next )
    {
        printf("%d\n", e->value);
    }
}


void append(struct element **lst, int value)
{
    struct element *neuesElement;
    
    /* Zeiger auf die Einfügeposition ermitteln, d.h. bis zum Ende laufen */
    while( *lst != NULL ) 
    {
        lst = &(*lst)->next;
    }

    neuesElement = malloc(sizeof(*neuesElement)); /* erzeuge ein neues Element */
    neuesElement->value = value;
    neuesElement->next = NULL; /* Wichtig für das Erkennen des Listenendes     */

    *lst = neuesElement;
    /* *lst ist der vorherige Null-Pointer dem das neue Element zugewiesen wird */
}

struct element *head;

/* Quelle: gip16 Folie 12 */
void insertFirst (struct element **lst, int val)
{
  struct element *neuesElement;
    // erstellt ein neues Element mit Zeiter
  
    neuesElement = malloc(sizeof(*neuesElement));
      // stellt Speicher für neues Element zur Verfügung
    neuesElement->value = val;
      // Inhalt des neuen Elements: val
    neuesElement->next = head;
    head = neuesElement;

    *lst = neuesElement;
}


int main()
{
    struct element *ListeA;
    struct element *ListeB;

    ListeA = NULL;      /* init. die Liste mit NULL = leere Liste */
    ListeB = NULL;

    append(&ListeA, 1); /* füge neues Element in die Liste ein    */
    append(&ListeA, 3); /* füge neues Element in die Liste ein    */
    append(&ListeA, 2); /* füge neues Element in die Liste ein    */

    printliste(ListeA); /* zeige alle Elemente der Liste an */


    // ListeA durchgehen
    for ( ; &ListeA != NULL; ListeA = ListeA->next )
    {
      insertFirst(&ListeB, ListeA->value);
    }

    printliste(ListeB);

    return 0;
}