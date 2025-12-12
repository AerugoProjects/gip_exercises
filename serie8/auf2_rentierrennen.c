/*
Damit am Weihnachtstag alle Geschenke pünktlich durch den Weihnachts-
mann  zugestellt werden können, braucht es jedes Jahr ein Gespann aus 
den  besten und schnellsten Rentieren. Um diese zu bestimmen, finden im 
Laufe des Dezembers die alljährlichen Rentierrennen am Nordpol statt. 
Wir wollen im Folgenden eine einfache Simulation dieser Rennen unter 
Verwendung von Würfeln implementieren.
An einem Rennen nehmen N Rentiere teil, denen jeweils eine eindeutige 
Startzahl von 1 bis N zugeteilt ist. Die Renndistanz ist aufgrund der 
großen Anzahl an nötigen Rennen auf 10 Meter festgelegt. Mit drei Wür-
feln, die jeweils Zahlen von 1 bis N  werfen können, wird der Rennver-
lauf dargestellt. Für jede gewürfelte Zahl wird das Rentier mit der 
entsprechenden Startnummer genau um einen  Meter dem Ziel nähergebracht. 
Sieger des Rennens ist jenes Rentier, welches als Erstes die Ziellinie
erreicht.

Schreiben Sie ein Programm in der Sprache C, das vom Benutzer die An-
zahl der Rentiere N > 3 einliest und ein derartiges Rennen simuliert! 
Während des Rennens soll dabei fortlaufend der aktuelle Stand auf dem 
Bildschirm ausgegeben werden. Das jeweils aktuell in Führung liegende 
Rentier soll dabei konkret benannt werden.

Es ist sinnvoll das Programm in mehrere Funktionen zu unterteilen. Ins-
besondere sollten Sie Funktionen zur Berechnung der Führungsposition 
und zur Ausgabe des aktuellen Stands vorsehen.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Funktion: Schnellstes Rentier
int giveIndexFastesReindeer(int array[],int dim)
{
  int max = array[0];
  int index = 0;
  for (int temp = 0; temp < dim; temp++)
  {
    if (max < array[temp])
    {  max = array[temp];
      index = temp;
    }
  }
  return index;
}


// Prozedur: Ausgabe des aktuellen Fortschritts
void showProgress(int array[],int dim)
{
  for (int temp = 0; temp < dim; temp++)
  {  
    printf("Rentier %3d: ", temp+1);
    for (int temp2 = 0; temp2 < array[temp]; temp2++)
      printf("*");
    printf("\n");
  }
  int indexFastesReindeer = giveIndexFastesReindeer(array,dim)+1;
  printf("schnellstes Rentier: %d\n\n", indexFastesReindeer);
}



int main(void)
{
  srand(time(NULL));
    // Zufallsgenerator initialisieren
  int numberReindeer = 0;
    // Anzahl an Rentierten
  
  do
  {
    printf("Geben Sie die Anzahl antretender Rentiere an (min. 4): ");
    scanf("%d", &numberReindeer);
  } while (numberReindeer <=3);
    // Einlesen der Anzahl an Rentieren

  int arrayReindeer[numberReindeer];
    // Array der Rentiere
  for (int temp = 0; temp < numberReindeer; temp++)
    arrayReindeer[temp] = 0;
  int indexFastesReindeer = 0;
    // Indes des schnellsten Rentierts im Array der Rentierte

  while (arrayReindeer[indexFastesReindeer] < 10)
  {
    int numberDice1 = rand() % numberReindeer;
    int numberDice2 = rand() % numberReindeer;
    int numberDice3 = rand() % numberReindeer;
      // würfeln, welche Rentiere einen Schritt vor rücken

    arrayReindeer[numberDice1] += 1;
    arrayReindeer[numberDice2] += 1;
    arrayReindeer[numberDice3] += 1;
      // gewürfelte Rentiere einen Schritt vorrücken
    
    indexFastesReindeer = giveIndexFastesReindeer(arrayReindeer,numberReindeer);
    showProgress(arrayReindeer,numberReindeer);
  }

  printf("\nDas schnellste Rentier aus der Auswahl ist:\n"); 
  printf("Rentier %d\n\n",indexFastesReindeer+1);

  return 0;
}