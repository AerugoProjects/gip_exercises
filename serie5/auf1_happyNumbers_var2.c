/*
Die fr¨ohlichen Zahlen zeichnen sich durch folgende Eigenschaft aus: Für eine 
positive ganze Zahl wird die Summe der Quadrate ihrer Ziffern gebildet. Mit der 
Summe wird dann genauso fortgefahren. Ergibt sich in diesem Prozess irgendwann 
der Wert 1, so wird die Zahl fröhlich genannt. Beispielsweise ist die Zahl 
n = 23 eine fröhliche Zahl, da: 23 → 2*2 + 3*3 = 13 → 1*1 + 3*3 = 10 → 1*1 + 0*0 = 1.
Alle nicht fröhlichen Zahlen sind traurige Zahlen. Beispielsweise ist die Zahl 
n = 3113 eine traurige Zahl, da: 3113 → 3*3 + 1*1 + 1*1 + 3*3 = 20 → 2*2 + 0*0 = 4
 → 4*4 = 16 → 1*1 + 6*6 = 37 → 3*3 + 7*7 = 58 → 5*5 + 8*8 = 89 → 8*8 + 9*9 = 145
 → 1*1 + 4*4 + 5*5 = 42 → 4*4 + 2*2 = 20 → ... . Für alle traurigen Zahlen mündet 
 die Iteration also in den Zyklus 20, 4, 16, 37, 58, 89, 145, 42.
Schreiben Sie ein C-Programm, das alle fröhlichen Zahlen im Intervall [1, 500] 
bestimmt und zeilenweise auf dem Bildschirm ausgibt.
*/

#include <stdio.h>

/*int main()
{
  int ssd, number, i, temp;

  number = 1;
  
  while (number > 0 && number <= 10)
  {
    temp = number;
    while (!(ssd == 1 || ssd == 4 || ssd == 16 || ssd == 37 || 
      ssd == 58 || ssd == 89 || ssd == 145 || ssd == 42 || ssd == 20))
    {
      ssd = 0;
      printf("temp %d\n", temp);
      for (i = temp; i > 0; i = i/10)
      {
        // printf("i: %d, ssd_old: %d, (i modulo 10) %d\n", i, ssd, i%10);
        ssd = ssd + (i%10) * (i%10);
        // printf("number %d, ssd %d, \n\n", number, ssd);
      }
      if (ssd == 1)
        printf("happy number: %d \n\n", number);
      else temp = ssd;
    }
    number += 1;
    ssd = 0;
  }
}*/

int main() {
  for (int number = 1; number <= 500; number++) {
    int temp = number;
    int ssd;
    do {
      ssd = 0;
      for (temp; temp > 0 ; temp /= 10) {
        ssd += (temp%10)*(temp%10);
      }
      temp = ssd;
    } while (ssd != 1 && ssd != 4);
    if (temp == 1)
      printf("%d is happy\n", number);
  }
}
