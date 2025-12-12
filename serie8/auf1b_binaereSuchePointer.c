/*
In dieser Aufgabe soll eine Reihung vom Basistyp int durchsucht werden. In der 
Vorlesung wurde bereits die lineare Suche vorgestellt, in der eine Reihung in 
eine Richtung durchlaufen und der Index des gesuchten Elements im Erfolgsfalls 
zurückgegeben wird (siehe Foliensatz zu Reihungen). Hier soll es nun um die
binäre Suche gehen.
Das binäre Suchverfahren arbeitet auf einer bereits sortierten Folge von Werten. 
Entsprechend soll für diese Aufgabe von einer (aufsteigend) sortierten Reihung 
ausgegangen werden. Im ersten Schritt wird das mittlere Element der Reihung mit 
der gesuchten Zahl verglichen. Handelt es sich um die gesuchte Zahl, wird die 
Position des Elements zurückgegeben. Ist die Zahl größer als das Element, wird 
in der rechten Hälfte der Reihung (der Hälfte mit den größeren Werten) nach dem 
selben Schema weiter gesucht. Ist die gesuchte Zahl kleiner, so wird hingegen in 
der linken Hälfte der Reihung mit der Suche fortgefahren. Besteht der Suchbereich 
aus einem einzelnen Element, ist die Suche beendet, da dieses entweder der ge-
suchten Zahl entspricht oder die Zahl nicht in der Reihung vorhanden ist.

a) Implementieren Sie die Funktion binarySearch in der Sprache C ohne Zeiger und
Zeigerarithmetik. Die Funktion soll als Parameter eine gesuchte Zahl und eine 
Reihung sowie deren Länge erhalten und mit Hilfe der entsprechenden Suchverfahren
die Zahl in der Reihung finden. Ist die Zahl vorhanden, soll deren Position 
zurückgegeben werden, sonst -1.

b) Realisieren Sie die binäre Suche erneut, aber diesmal mit Hilfe von Zeigern 
und Zeigerarithmetik in einer eigenen Funktion.

c) Verwenden Sie die implementierten Funktionen in einem Hauptprogramm, um eine 
vom Benutzer eingegebene Zahl in einer Reihung zu suchen, welche die Primzahlen 
bis 100 enthält, und im Erfolgsfall deren Position ausgibt.
*/

#include <stdio.h>

int binarySearch (int numberInQuestion, int *pointer, int min, int max)
{
  int middle = min + (max - min) / 2;
    // index in der Mitte des Arrays -> Stelle an der die Zahl verglichen wird
  if ( (max - min == 1 || max - min == 0) && numberInQuestion != *(pointer+middle))
    return -1;
    // wenn die Zahl nicht gefunden wurde, gib -1 zurück
  if (numberInQuestion == *(pointer+middle))
    return middle;
    // wenn die gesuchte Zahl an der Stelle index steht, gib den Index zurück
  
  else
  {
    if (numberInQuestion < *(pointer+middle))
    {
      max = middle - 1;
      binarySearch(numberInQuestion,pointer,min,max);
    }

    else
    {
      min = middle + 1;
      binarySearch(numberInQuestion,pointer,min,max);
    }
  }
}

int main(void)
{
  int numberInQuestion;
    // Zahl die in primeNumbers gesucht werden soll
  int primeNumbers[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,
    61,67,71,73,79,83,89,97};
    // zu durchsuchendes Array mit den Primzahlen bis 100
  int min = 0;
    // index für die erste Zahl im Array
  int max = 24;
    // index der letzten Zahl im Array
  int found;
    // Ergebnis von binarySearch
  int *pointerPrimeNumbers = primeNumbers;
    // Pointer auf primeNumbers

  printf("Geben Sie eine Zahl zwischen 0 und 100 ein: ");
  scanf("%d", &numberInQuestion);

  if (numberInQuestion > 100)
    printf("Es handelt sich bei %d nicht um eine Zahl kleiner 100.\n",numberInQuestion);
  else
    found = binarySearch(numberInQuestion,pointerPrimeNumbers,min,max);
  
  if (found == -1 && numberInQuestion < 100)
    printf("Die Zahl %d ist keine Primzahl unter 100. \n",numberInQuestion);
  else
    printf("Bei der Zahl %d handelt es sich um die %d. Primzahl. \n", numberInQuestion, found+1);

  return 0;
}