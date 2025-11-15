#include <stdio.h>

int main(){
  // einzugebende Zahlen
  int num1, num2, num3;
  // kleinere Zahl von num1 und num2
  int min, max;

  // Benutzer nach drei Zahlen fragen
  printf("Bitte geben Sie drei ganze Zahlen ein: ");
  // Zahlen vom Bildschirm einlesen
  scanf("%d %d %d", &num1, &num2, &num3);

  // testen, ob num1 oder num2 kleiner ist
  // Zuordnung der kleineren Zahl zu min und größere Zahl zu max
  if (num1 <= num2)
    {
      min = num1; // num1 num2 == min max
      max = num2;
    }

  else
    {
      min = num2; // num2 num1 == min max
      max = num1;
    }

  // testen, ob num3 zwischen min und max liegt
  // Ausgabe der sortierten Zahlen von klein nach groß
  if (min <= num3 && max >= num3)
    {
      printf("%d %d %d\n", min, num3, max);
    }
    
  else
    {
      printf("%d %d %d\n", num3, min, max);
    }

  return 0;
}