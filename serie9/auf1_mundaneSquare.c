/*
Diese Anordnung von Zahlen besitzt die Eigenschaft, dass alle
Spalten, Zeilen und die zwei Diagonalen die gleiche Summe
besitzen. Realisieren Sie ein Programm in der Sprache C,
welches ein magisches Quadrat mit ungerader Spalten- und
Zeilenlänge erzeugt und ausgibt. Implementieren Sie dazu eine
Funktion die für eine ungerade positive ganze Zahl n ein
magisches Quadrat dieser Spalten- und Zeilenlänge nach dem
im Folgenden beschriebenen Algorithmus erzeugt:

Die Zahl 1 wird in das Feld senkrecht unter der Mitte des
Quadrates eingetragen. Wiederhole danach folgende Schritte
bis das Quadrat vollständig ist: Steht eine Zahl in einem
Feld, so kommt ihr Nachfolger in die nächste Spalte und
nächste Zeile (in das Feld rechts unterhalb des aktuellen
Feldes). Ist dieses Feld schon besetzt, so wird ausgehend
von diesem besetzten Feld ein freies Feld gesucht: Besuche
das Feld in der nächsten Zeile und vorherigen Spalte,
(das Feld links unterhalb des aktuellen Feldes). Fahre fort,
bis ein freies Feld gefunden ist. Wird das Quadrat dabei
unten verlassen, so wird oben fortgefahren. Wird das Quadrat
rechts verlassen, wird links fortgefahren. Analog wird rechts
fortgefahren, wenn das Quadrat links verlassen wird.
*/

/*
1. im Feld unter dem mittleren Feld eine 1 schreiben
2. nächste Zahl in das Feld unten rechts eintragen
3. wenn das Feld schon besetzt ist, gehe zum Feld unten links
4. oben raus -> unten rein
    rechts raus -> links rein
    links raus -> rechts rein
*/

#include <stdio.h>


int main()
{
  int n = 0;
    // Größe des magischen Quadrates
  do{
    printf("Geben sie eine ungerade Anzahl an Feldern für ");
    printf("das magische Quadrat an: ");
    scanf("%d", &n);
  } while (n%2 != 1);
    // Abfragen der Größe des magischen Quadrates

  int magicSquare[n][n];
    // erstellen des magischen Quadrates
  for (int temp1 = 0; temp1 < n; temp1++)
  {
    for (int temp2 = 0; temp2 < n; temp2++)
      magicSquare[temp1][temp2] = 0;
  }
    // alle Einträge in magicSquare auf 0 setzten

  int row = n/2 + 1;
  int col = n/2;
    // Startkoordinaten
  magicSquare[row][col] = 1;
    // 1 in das Feld unter der Mitte eintragen
  
  for (int counter = 2; counter <= n*n; counter++)
  {
    if (magicSquare[(row+1)%n][(col+1)%n] == 0)
      {
        magicSquare[(row+1)%n][(col+1)%n] = counter;
        row = row + 1;
        col = col + 1;
      }
    else
      {
        magicSquare[(row+1)%n][(n+col-1)%n] = counter;
        row = row + 1;
        col = n + col - 1;
      }
  }


  
  for (int temp1 = 0; temp1 < n; temp1++)
  {
    for (int temp2 = 0; temp2 < n; temp2++)
      printf("%3d ", magicSquare[temp1][temp2]);
    printf("\n");
  }
  // Ausgabe des magischen Quadrates

  // Prüfsumme berechnen
  int summe1 = 0;
  for (int temp = 0; temp < n; temp++)
  {
    summe1 = summe1 + magicSquare[temp][0];
  }

  int summe2 = 0;
  for (int temp = 0; temp < n; temp++)
  {
    summe2 = summe2 + magicSquare[2][temp];
  }

  printf("Prüfsumme 1: %d\n", summe1); 
  printf("Prüfsumme 2: %d\n", summe2);

  return 0;
}