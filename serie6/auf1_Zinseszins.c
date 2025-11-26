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
}