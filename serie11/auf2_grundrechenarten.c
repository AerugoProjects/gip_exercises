/*
Die Grundrechenarten für ganze Zahlen lassen sich mit Ein-
schränkungen relativ leicht auf das Inkrementieren und De-
krementieren eines Wertes zurückführen. Schreiben Sie rekur-
sive Funktionen in der Programmiersprache C für

a) Addition add(a, b), mit a >= 0 und b >= 0

b) Multiplikation mult(a, b), mit a >= 0 und b >= 0

Testen Sie Ihre Funktionen in einem geeigneten Hauptprogramm!
Hinweise: Als bekannte Operationen dürfen Sie ausschließlich
die Bestimmung des Nachfolgers und des Vorgängers voraussetzen
(+1, -1). Bei der Multiplikation können Sie auf add aus a)
zurückgreifen.
*/

#include <stdio.h>

int add(int a, int b)
{
  if (b == 0)
    return a;
    // a + 0 = a
  if (a == 0)
    return b;
    // 0 + b = b
  return add( ++a , --b );
}


int mult(int a, int b)
{
  if (a == 0 || b == 0) return 0;
    // a * 0 = 0  und  0 * b = 0
  if (a == 1) return b;
    // 1 * b = b
  if (b == 1) return a;
    // a * 1 = a
  return add( a , mult(a,--b) );
}


int main (void)
{
  int a = 0;
  int b = 0;
    // a und b sind Zahlen, die miteinander verrechnet werden
  do
  {
    printf("Geben sie zwei positive Zahlen ein, die miteinander");
    printf(" addiert und multipliziert werden sollen.\n");
    printf("Format: a b\n");
    scanf("%d %d", &a, &b);
      // einlesen von a und b
  } while (a < 0 || b < 0);

  int sum = add(a, b);
  int prod = mult(a, b);

  printf("\nSumme aus a und b: %d", sum);
  printf("\nProdukt aus a und b: %d\n", prod);
  return 0;
}