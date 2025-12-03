#include <stdio.h>

double lin_function(double x)
{
  return 2 * x + 1;
}

void table(double (*function)(double), double min, double max, double step)
{
  double currentStep = 0;

  for(currentStep = min;currentStep < max; currentStep += step)
    {
      printf("%.2lf  %.2lf\n", currentStep, function(currentStep));
    }
}


int main(void)
{
  double min = 0;
  double max = 0;
  double step = 0;
  

  double (*function)(double) = lin_function;

  do
  { /* Grenzen und Schrittweite einlesen, bis die untere Grenze kleiner als die
    obere Grenze ist und die Schrittweite innerhalb der Grenzen liegt*/
    printf("Geben Sie bitte die untere Grenze, obere Grenze und die Schrittweite an:\n");
    scanf("%lf %lf %lf", &min, &max, &step);
    //printf("%lf %lf %lf", min, max, step);
  } while (max < min && step > (max-min));

  printf("\nf(x) = 2x + 1\n");
  printf("\n x\ty\n");
  table(function,min,max,step);

  return 0;
}