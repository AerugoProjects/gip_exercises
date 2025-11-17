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

// Funktion zur Bestimmung der glücklichen Zahlen
int IsHappy(int number)
{
  int ssd, i;
  ssd = 0;
  for (i = number; i > 0; i = i/10)
    // Berechnung der Summe der Quradrate der Ziffern der Quersumme = ssd
    {
      ssd = ssd + (i%10)*(i%10);
    }
  // prüfen der Abbruchbedingung
  if (ssd == 4 || ssd == 16 || ssd == 37 || ssd == 58 || ssd == 89 || ssd == 145
       || ssd == 42 || ssd == 20)
    return 0;
  // prüfen der Bedingung für eine fröhliche Zahl
  else if (ssd == 1)
    return 1;
  // erneutes Aufrufen der Funktion
  else return IsHappy(ssd);
}

int main()
{
  int number;

  for (number = 1; number <= 500; number++)
    {
      // Wenn die Zahl eine fröhliche Zahl ist: Ausgabe der Zahl auf der Konsole
      if (IsHappy(number)) printf("%d\n", number);
    }
  
  return 0;
}