#include <stdio.h>
#include <stdlib.h>

// // //
// 
// structs
// 
// // //

/* Datentyp Node erstellen: Datentyp für die einzelnen Knoten
mit einem Wert val und Zeigern zum vorherigen Element (parent)*/

typedef struct Node
{
  int value;

  struct Node *parent;
}Node;


// // //
// 
// Funktionen
// 
// // //

/* 2a -- testen, ob die Hexe den Ausgang blockiert */
void testHexe (char string[], int dim)
{
  if (string[13] == 'X')
    // Wenn Hexe auf Feld 13 ( =Ausgang) steht:
  {
    printf("Die Hexe blockiert den Ausgang!\n");
      // Ausgabe, dass die Hexe den Ausgang blockiert
    exit(0);
      // Programm an dieser Stelle ordnungsgemäß beenden
      
/* exit(0): Programm wurde erfolgreich ausgeführt und an dieser Stelle
bewusst beendet. Es gab keinen Fehler -> exit(0) */
  }
}


/* 2b -- testen, ob ein Lolli-Baum den Ausgang blockiert */
void testLolli (char string[], int dim)
{
  if (string[13] == 'T')
    // Wenn Lolli-Baum auf Feld 13 ( =Ausgang) steht:
  {
    printf("Ein Lolli-Baum blockiert den Ausgang!\n");
      // Ausgabe, dass ein Lolli-Baum den Ausgang blockiert
    exit(0);
      // Programm an dieser Stelle ordnungsgemäß beenden
  }
}



/* 3. Ausgabe einer Konfiguration als 2d-Gitter */
void printMap(char string[], int dim)
{
  for (int temp = 0; temp < dim; temp++)
  {
    if (temp == 0) 
    {
      printf("+----+\n");
      printf("|");
    }
    printf("%c", string[temp]);
    if (temp%4 == 3 && temp <14) printf("|\n|");
    if (temp == 15)
    {
      printf("|\n+----+\n");
    }
  }
}



/* 5. Bewegen der Spielsteine */
int emptyPlace (char string[], int dim, int index)
{
  if (string[index] == ' ') return 1;
  else return 0;
  /* wenn das Feld an der Stelle index leer ist, gibt true
  zurück, sonst gibt false zurück */
}

/* 
void moveHaenselUp (char string[], int dim)
{
  int haensel = -1;
  // haensel-index außerhalb des arrays
  for (int temp = 0; temp < dim; temp++)
  {
    if (string[temp] = 'H')
    {
      haensel = temp;
      break;
      /* wenn Haensel auf der Karte gefunden wurde, speicher
      den Index von Haensel in haensel und verlasse den Loop
    }
  }
  
  if (haensel-4 > 0 && emptyPlace(string, dim, haensel-4))
  /* wenn das Feld über Haensel noch auf der Map liegt und
  frei ist, bewege Haensel ein Feld nach oben
  {
    string[haensel-4] = 'H';
    string[haensel] = ' ';
  }

} */

/* Funktion um ein 1x1 großes Element um ein Feld nach oben
zu verschieben */
void move11Up (char string[], int dim, char item)
{
  int index = -1;
  // Index des Items auf -1 setzten (außerhalb des Arrays)
  
  for (int temp = 0; temp < dim; temp++)
  {
    if ( string[temp] = item )
    {
      index = temp;
      break;
      /* wenn das Item auf der Karte gefunden wurde, speicher
      den Index in index und verlasse den Loop */
    }
  }

  if ( index-4 > 0 && emptyPlace(string, dim, index-4) )
  /* wenn das darüberliegende Feld noch auf der Karte liegt
  und frei ist: bewege das Item dahin */
  {
    string[index-4] = item;
    string[index] = ' ';
  }
}


/* Funktion um ein 1x1 großes Element um ein Feld nach unten
zu verschieben */
void move11Down (char string[], int dim, char item)
{
  int index = -1;
  // Index des Items auf -1 setzten (außerhalb des Arrays)
  
  for (int temp = 0; temp < dim; temp++)
  {
    if ( string[temp] = item )
    {
      index = temp;
      break;
      /* wenn das Item auf der Karte gefunden wurde, speicher
      den Index in index und verlasse den Loop */
    }
  }

  if ( index+4 < dim && emptyPlace(string, dim, index+4) )
  /* wenn das darüberliegende Feld noch auf der Karte liegt
  und frei ist: bewege das Item dahin */
  {
    string[index+4] = item;
    string[index] = ' ';
  }
}






















/* 8a -- testen, ob Haensel den Ausgang erreicht hat */
int testExitHaensel (char string[], int dim)
{
  if (string[13] == 'H')  return 1;
  else return 0;
}


/* 8b -- testen, ob Gretel den Ausgang erreicht hat */
int testExitGretel (char string[], int dim)
{
  if (string[13] == 'G')  return 1;
  else return 0;
}





// // //
// 
// main
// 
// // //

int main (void)
{

/* 1. Spielkonfiguration von der Konsole einlesen */
  
  char input[17] = "XXH1 TT1   T    ";
    // für Testzwecke immer diese Konfiguration nehmen

  printf("Geben Sie die Startkonfiguration ein. ");
  printf("Beachten Sie dabei folgende Codierung: \n");
  printf("H -- Haensel\n");
  printf("G -- Gretel\n");
  printf("X -- Hexenhaus\n");
  printf("1, 2 -- Kaugummikugeln (je 2 Felder)\n");
  printf("T -- Lolli-Baum\n");
  printf("' ' -- freies Feld\n");

  //scanf("%16s", &input);


/* 2. Prüfen, ob Startkonfiguration erlaubt ist 
  a. Hexe blockiert Ausgang?
  b. Lolli-Baum blockiert Ausgang?
  -> Wenn Ausgang blockiert: nicht lösbar -> Programm beenden */

testHexe(input, 17);
testLolli(input, 17);


/* 3. Ausgabe der Startkonfiguration als 2d-Gitter (printBoard) */

printMap(input, 17);


/* TODO: 4. Speichern der Startkonfiguration in Knoten */

/* TODO: 5. Bewegen der Spielsteine nach folgender Hierachie:
  (vorher immer testen, ob das Zielfeld frei ist (emptyPlace))
  a-d. Haensel (rechts, runter, links, hoch)
  e-h. Gretel (rechts, runter, links, hoch)
  i-l. Kaugummibaum 1 (rechts, runter, links, hoch)
  m-p. Kaugummibaum 2 (rechts, runter, links, hoch)
  q.   prüfen, ob Lolli-Baum auf mobilem Feld steht,
        dann n-q sonst nicht bewegen
  r-u. Lolli-Baum (rechts, runter, links, hoch) */

/* TODO: 6. Prüfen, ob im Kreis gelaufen (pointer nach oben gehen 
  und aktuelle mit vorherigen Konfigurationen vergleichen, 
  als Sackgasse markieren und mit parent weiter machen) */

/* TODO: 7. entstehende Spielkonfiguration in eigenem Array in eigenem
  Knoten speichern (mit Link zum Vorgaenger und Nachfolger (mehrere mögl.)) */

/* 8. Zielkonfiguration erreicht? (Haensel/Gretel auf Feld 13)
  a. ja -> weiter mit 8
  b. nein -> wiederhole ab 5 */
  testExitHaensel(input, 17);
  testExitGretel(input, 17);

/* TODO: 9. Pfad rückwärts nach oben gehen und die Spielkonfiguration
  in einer neuen Liste speichern (immer vorne dran schreiben
  -> älteste Konfiguration vorne in der Liste) */

/* TODO: 10. neue Liste von vorne nach hinten durchgehen und die Spiel-
  konfigurationen jeweils auf der Konsole ausgeben */

  return 0;
}