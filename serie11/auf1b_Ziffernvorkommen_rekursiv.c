/*
Geben Sie für die folgenden Probleme jeweils einen rekursiven Algorithmus in Form einer C-Funktion an:

b) Für eine natürliche Zahl n → 0 soll die Anzahl der Vor-
kommen einer Ziffer bestimmt werden. Sowohl die Zahl n als 
auch die Ziffer sollen der Funktion dabei als Parameter über-
geben werden.
*/

#include <stdio.h>

int funcCountDigit (int number, int digit)
{
  if (number < digit)
    // Zahl ist kleiner als gesuchte Ziffer
    return 0;
  if (number == digit)
    // Zahl ist gleich der gesuchten Ziffer
    return 1;
  if (number/10 > 0 && number < digit)
  {
    if (number % 10 == digit)
      return ( 1 + funcCountDigit(number/10,digit) );
    else
      return funcCountDigit(number/10,digit);
  }
}


int main(void)
{
  int number = 0;
    // Zahl
  int digit = 0;
    // gesuchte Ziffer
  
  printf("Geben sie Zahl ein, die nach einer Ziffer durchsucht");
  printf(" werden soll: ");
  scanf("%d", &number);
    // Zahl von Benutzer abfragen
  
  printf("Geben sie die zu zählende Ziffer ein: ");
  scanf("%1d", &digit);
    // Ziffer von Benutzer abfragen

  printf("Die gesuchte Ziffer %d kommt %d mal in %d vor.\n", 
    digit, funcCountDigit(number, digit), number);
    // Ausgabe des Ergebnis
  
  return 0;
}