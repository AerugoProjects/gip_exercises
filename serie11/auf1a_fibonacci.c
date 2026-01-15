/*
Geben Sie für die folgenden Probleme jeweils einen rekursiven
Algorithmus in Form einer C-Funktion an:

a) Die Fibonacci-Zahlen sind durch eine rekursive Bildungs-
vorschrift wie folgt definiert:
f0 = 1, f1 = 1 und für alle n → 2 fn = fn→1 + fn→2 . Für eine
natürliche Zahl n → 0 soll die n-te Fibonacci-Zahl bestimmt
werden.

*/

#include <stdio.h>

int fibonacci (int n)
{
  if (n == 1 || n == 2)
    return 1;
  else
    return fibonacci(n-1)+fibonacci(n-2);
}

int main (void)
{
  int n = 0;
  
  // Abfragen von n
  printf("Geben sie an für wie viele Zahlen die Fibonacci-Folge");
  printf(" berechnet werden soll: ");
  scanf("%d", &n);

  // Ausgabe der Fibonacci-Zahl
  printf("%d\n",fibonacci(n));


  return 0;
}