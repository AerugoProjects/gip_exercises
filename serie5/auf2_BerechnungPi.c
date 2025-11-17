/*
Schreiben Sie ein Programm, welches pi auf eine gegebene Genauigkeit nach dem 
Verfahren von Leipniz berechnet! Dazu soll vom Benutzer ein Genauigkeitswert (z.B.
0.001 oder 1e-6) eingelesen werden. Die Iteration bricht ab, wenn sich das Ergebnis
in einem Schritt um weniger als der angegebene Wert ändert.
Vergleicen Sie den berechneten Wert mit M_PI (#include <math.h>) und geben Sie 
den Fehler aus.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main()
{
  // notwendig für den Vorzeichenwechsel
  int sign = 1; 
  // notwendig für die Berechnung der Reihe
  int n = 1; 

  // neu berechneter Wert von pi mit initialem Wert 4
  double piNew = 4; 
  // vorheriger Wert von pi
  double piOld; 
  // von Benutzer vorgegebene Genauigkeit
  double accuracy; 
  double diffMPIpiNew;

  printf("Geben Sie bitte die Genauigkeit an, mit der pi nach der Leipniz-Reihe");
  printf("berechnet werden soll: \n");
  // Einlesen der Genauigkeit in Dezimal oder Exponentialdarstellung
  scanf("%lg", &accuracy);

  do
  {
    // Vorzeichenwechsel
    sign = sign * (-1);
    // Vergrößerung des Nenners um 2
    n = n + 2;
    // bisher berechneter Wert für pi
    piOld = piNew; 
    
    /*
      Berechnung von pi nach der Fomel:
      pi = 4 - 4/3 + 4/5 - 4/7 + 4/9 - ...
    */
    piNew = piOld + (sign * 4.0/n);

  } while (fabs(piNew-piOld) >= accuracy);
  
  // Berechnung der Differenz zwischen dem berechneten und gegeben pi-Wert
  diffMPIpiNew = fabs(M_PI-piNew);

  printf("\ngeforderte Genauigkeit: %f\n", accuracy);
  printf("berechneter Wert für pi: %f\n", piNew);
  printf("Differenz zwischen berechnetem Wert und M_PI: %f\n\n", diffMPIpiNew);

  return 0;
}