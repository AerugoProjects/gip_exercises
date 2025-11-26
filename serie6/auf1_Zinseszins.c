/*
Die Verzinsung eines Kapitalvermögens K0 unter einem Zinssatz p nach n Jahren 
kann unter Verwendung der folgenden Zinseszinsformel berechnet werden:
Kn = K0 · ( 1 + p/100)^n
Schreiben Sie ein Programm in der Sprache C, das eine Zinseszinstabelle am 
Bildschirm ausgibt. Dazu sollen die Gesamtlaufzeit in Jahren, der Zinssatz und 
das Startkapital vom Bildschirm eingelesen. Anschließend soll für jedes Jahr der 
Laufzeit das verzinste Kapital berechnet sowie ausgegeben werden. Runden Sie das 
verzinste Kapital bei der Ausgabe auf zwei Nachkommastellen!

Hinweise: Beachten Sie, dass sowohl das Startkapital, als auch der Zinssatz und 
das verzinste Kapital keine ganzen Zahlen sein müssen. Verwenden Sie einen 
passenden Datentyp.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
  int jahr;              // n
  double zinssatz;       // p
  double startkapital;   // k_0
  double neuesKapital;   // k_n
 
  // Startkapital einlesen
  printf("Startkaptial: ");
  scanf("%lf", &startkapital);

  // Zinssatz einlesen
  printf("\nZinssatz: ");
  scanf("%lf", &zinssatz);

  // betrachtete Jahre einlesen
  printf("\nJahre: ");
  scanf("%d", &jahr);

  // Ausgabe des Startkaptials
  printf("\nStartkaptial: %lf \n", startkapital);
  printf("Zinssatz: %lf\n", zinssatz);

  for (int i = 1; i <= jahr; i++)
  {
    double zins = 1 + zinssatz/100;
    neuesKapital = startkapital * pow(zins, jahr);
    printf("Kaptial nach %d Jahren: %lf\n", jahr, neuesKapital);
  }

  return 0;
}