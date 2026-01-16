/*
Geben Sie für die folgenden Probleme jeweils einen rekursiven
Algorithmus in Form einer C-Funktion an:

c) Für eine natürliche Zahl n >= 0 soll ermittelt werden, ob
die Ziffern der Zahl von links nach rechts gelesen absteigend
sortiert sind (wie beispielsweise in 9876543210 oder 
98666631111). Falls ja, soll die Funktion 1 zurückgeben,
falls nein 0.
*/

#include <stdio.h>
#include <math.h>


int funcSortDigits(int number, int smallesDigit)
{
  if (number%10 >= smallesDigit && number/10 == 0)
  /* number nicht weiter durch 10 teilbar -> nur noch eine Ziffer
  und größer gleich smallesDigit */
    return 1;
  
  if (number%10 == smallesDigit)
  /* wenn die letzte Ziffer gleich der kleinsten Ziffer ist:
  Stelle merken (+1) und zur nächsten Stelle gehen (number/10) */
    return ( funcSortDigits(number/10,smallesDigit) );
  
  if (number%10 > smallesDigit)
  /* wenn die letze Ziffer größer als die bisherige Ziffer ist:
  Stelle merken (+1), größte bisherige Ziffer merken und zur
  nächsten Stelle gehen */
    {
      smallesDigit = number%10;
      return ( funcSortDigits(number/10,smallesDigit) );
    }
  if (number%10 < smallesDigit)
  /* wenn eine Zahl auftaucht, die kleiner als die bisher größte
  Ziffer ist, abbrechen und zur Hauptfunktion zurückkehrern */
    return 0;
  
}


int main(void)
{
  int testnumber = 0;
  // Zahl deren Ziffer getestet werden

  printf("Geben Sie eine Zahl ein, bei der getestet werden ");
  printf("soll, ob die Ziffer in absteigender Reihenfolge ");
  printf("sortiert sind: ");
  scanf("%d",&testnumber);
  // Abfrage des Werts für testnumber

  if (funcSortDigits(testnumber,0))
    printf("\nDie Ziffern sind absteigend sortiert.\n");
  else
    printf("\nDie Ziffern sind nicht sortiert.\n");

  return 0;
}