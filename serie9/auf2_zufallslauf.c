/*
Wir stellen uns einen Sucher vor, der in einem 2D-Punktegitter
der Größe n → n von einem Punkt zum nächsten Punkt gehen kann.
Mit jedem Schritt geht er vom Punkt, auf dem er steht, zu
einem Nachbarpunkt nach Norden, Süden, Osten oder Westen.
Da der Sucher keinen Plan hat, wählt er jedesmal zufällig aus,
in welche Richtung er gehen soll.

Der Sucher durchläuft keinen Punkt doppelt. Wenn er also zu-
fällig entschieden hat, z.B. nach Westen zu gehen, aber dort
bereits gewesen war, dann geht er stattdessen in eine andere
Richtung. Dabei wird es irgendwann vorkommen, dass er auf
einem Punkt steht, dessen vier Nachbarpunkte er bereits durch-
laufen hat. Das beendet den Lauf des Suchers. Für die Ränder
gilt es folgende Sonderregel zu beachten: Wenn der Sucher vom
Nordrand des Gitters einen Schritt nach Norden macht, landet
er auf dem entsprechenden Punkt am Südrand, und entsprechend
für die anderen Ränder.

Schreiben Sie ein Programm in der Sprache C, das einen solchen
schleifenfreien Zufallslauf simuliert. Der Benutzer soll zu
Beginn die Größe n des quadratischen Punktgitters eingeben.
Der Sucher startet für den Lauf immer an Position (0, 0).

Geben Sie die Anzahl der Schritte aus, die der Sucher bis
zum Ende des Laufs gemacht hat.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));
    // Zufallszahlgenerator initialisieren


  int n = 3;
    // Größe des Quadrates
  /*do{
    printf("Geben Sie die Seitenlaenge des Quadrats an: ");
    scanf("%d", &n);
  } while (n < 2);*/
    // Abfragen der Größe des magischen Quadrates

    
  int square[n][n];
    // erstellen des Quadrats
  for (int temp1 = 0; temp1 < n; temp1++)
  {
    for (int temp2 = 0; temp2 < n; temp2++)
      square[temp1][temp2] = 0;
  }
    // alle Werte in square auf 0 setzten


  int row = 0, col = 0; // Startposition
  int counterSteps = 0; // Anzahl der Schritte

  int wayOut = 1; // wayOut = true
    // Bedingung für while-Schleife
  
  
  square[row][col] = 1;
    // Beginn an 0 0
    // besuchte Felder auf 1 setzen
  
  printf("Weg: ");
  while (wayOut)
    // wiederhole, solange noch Wege möglich sind (wayOut=1)
  {
    if (counterSteps%30 == 0)
      printf("\n");
    
    int randNr = rand() % 4;
      // Zufallszahl ziehen: 0 1 2 3
    
    switch (randNr)
    {
    case 0: // gehe nach Norden
      if (square[(n+row-1)%n][col%n] == 0)
      {
        printf("N ");
        square[(n+row-1)%n][col] = 1;
          // markiere das Feld als besucht
        row = (n+row-1)%n,
          // aktualisiere den Standord
        counterSteps++;
          // Anzahl der Schritte +1
      }
      break;
    case 1: // gehe nach Osten
      if (square[row%n][(col+1)%n] == 0)
      {
        printf("O ");
        square[(row)%n][(col+1)%n] = 1;
        col = (col+1)%n;
        counterSteps++;
      }
      break;
    case 2: // gehe nach Sueden
      if (square[(row+1)%n][col%n] == 0)
      {
        printf("S ");
        square[(row+1)%n][col] = 1;
        row = (row+1)%n;
        counterSteps++;
      }
      break;
    case 3: // gehe nach Westen
      if (square[row%n][(n+col-1)%n] == 0)
      {
        printf("W ");
        square[row%n][(n+col-1)%n] = 1;
        col = (n+col-1)%n;
        counterSteps++;
      }
      break;
    }

    // testen, ob noch weitere Wege möglich sind
    if (square[(n+row-1)%n][col%n] != 0
        && square[row%n][(col+1)%n] != 0
        && square[(row+1)%n][col%n] != 0
        && square[row%n][(n+col-1)%n] != 0)
      wayOut = 0;
        // wenn keine weiteren Wege möglich: wayOut=0
        // -> wayOut = false    
  } // von while-Schleife
  
  
  printf("\n\nAnzahl gemachter Schritte: %d\n\n", counterSteps);
    // Ausgabe der gemachten Schritte
  
  for (int temp1 = 0; temp1 < n; temp1++)
  {
    for (int temp2 = 0; temp2 < n; temp2++)
      printf("%d ", square[temp1][temp2]);
    printf("\n");
  }
    // Ausgabe von square
  printf("\n");
  
  return 0;
}

/*
Schritten abhängig von der Kantenlaenge n

n = 3
 8  8  7  7  7      8  8  8  8  7

n = 4
15 14 15 13 11     15 13 14 15 14

n = 5
21 24 19 22 21     10 19  9 23 21

n = 10
53 53 13 60 30     43 53 70 68 57

*/