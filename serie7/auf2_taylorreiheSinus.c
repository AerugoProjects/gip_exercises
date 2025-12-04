#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funktion zur Berechnung einer Fakultät
double fact(int n)
{
  if (n==1)
    return 1;
  else
    //printf("@fact: n %d\n",n);
    return fact(n-1)*n;
}

// Funktion für die Taylor-Reihe
double taylorSinus(int stop, double x) 
{
// Funktion: 
// sin(x) = sum_0^inf (-1)^n * ( x^(2n+1) ) / ((2n+1)!)

  int sign = 1; 
    // für wechselndes Vorzeichen
  int n = 1;
  
  double taylorSin = 0;
  
  for (taylorSin = 0; n <= stop; n+=2)
  {
    double fac = fact(n);
    //printf("fac1: %lf", fac);
    taylorSin = taylorSin + sign * pow(x,n)/fac;
    sign = sign * (-1);
    //printf("\n\ntaylorSin %.4lf, sign %d, x %.1lf, n %d\n",taylorSin, sign, x, n);
    //printf("pow(x,n) %lf, fac(n) %lf\n\n", pow(x,n),fact(n));
  }

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

  printf("Geben Sie die maximale Potenz der Tayler-Reihe an: ");
  scanf("%d", &maxPot);

  printf("\n x\t  sin(x) \t  taylor(x)\n");

  while (x >= 0 && x <= 10) // TODO set x <= 10
  {
    mathSin = sin(x);
    taylorSin = taylorSinus(maxPot,x);

    printf("%.1lf\t%7.4lf\t\t%9.4lf\n", x, mathSin,taylorSin);
    x = x + step;
  }


  return 0;
}