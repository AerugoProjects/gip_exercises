#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funktion zur Berechnung einer Fakultät
int fact(int n)
{
  if (n==1)
    return 1;
  else
    return fact(n-1)*n;
}

// Funktion für die Taylor-Reihe
double taylorSinus(int (*fact)(int), int stop, double x) 
{
// Funktion: 
// sin(x) = sum_0^inf (-1)^n * ( x^(2n+1) ) / ((2n+1)!)

  int sign = -1; 
    // für wechselndes Vorzeichen
  int n = 1;
  
  double taylorSin;
  
  for (taylorSin = 0; n <= stop; n*=2, sign=sign*-1)
    taylorSin = taylorSin + sign * (x,n)/fact(n);
  
  return taylorSin;
}

int main(void)
{
  int maxPot;
    // größte Potenz der Taylor-Reihe (vom Nutzer einzugeben)
  double x = 0;
    // Winkel in rad
  double mathSin;
    // sin aus der math.h Funktion
  double taylorSin;
    // sin aus der Taylor-Reihe
  double step = 0.5;

  printf("Geben Sie die maximale Potenz der Tayler-Reihe an:");
  scanf("%d\n", &maxPot);

  while (x >= 0 && x <= 10)
  {
    mathSin = sin(x);
    taylorSin = taylorSinus(fact,maxPot,x);

    printf("\nx\tsin(x)\ttaylor(x)\n");
    printf("%.1lf %.4lf %.4lf", x, mathSin,taylorSin);
    x = x + step;
  }


  return 0;
}