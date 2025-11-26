/*
Ein C-Programm soll eine Statistik zu Trainingsdaten im Weitsprung anlegen. 
Dazu sollen die Sprungweiten x1 , x2 , x3 , . . . in Form von Gleitkommazahlen 
fortlaufend am Bildschirm eingegeben werden. Die Eingabe der Daten soll enden, 
falls eine Zahl kleiner oder gleich Null x ≤ 0 eingegeben wurde (die natürlich 
nicht zu den Trainingsdaten gezählt wird). Anschließend sollen für die ein-
gelesenen Trainingsdaten folgende Statistikwerte am Bildschirm ausgegeben werden:
- Anzahl der Sprünge
- die zwei größten Weiten und die kleinste Weite
- die mittlere Weite (arithmetisches Mittel)
- die Differenz von größter und kleinster Weite
Hinweis: Für die Lösung dieser Aufgabe sollen keine Arrays verwendet werden!
*/

#include <stdio.h>

int main(void)
{
  double min = 0;           // kleinster Wert
  double max = 0;           // größter Wert
  double max2 = 0;          // zweit größter Wert
  int counter_sprung = 0;   // Anzahl der Sprünge
  double weite;             // Weite des aktuellen Sprungs
  double gesamtweite = 0;   // Summe der gesprungenen Strecke
  double durchschnitt;      // durchschnittliche Sprungweite
  double maxDifferenz;      // Differenz zwischen min und max

  while (weite > 0)
  {
    // Sprungweite einlesen
    printf("Sprungweite: ");
    scanf("%lf", &weite);
    if (weite <= 0) break;
    // Sprünge zählen
    counter_sprung += 1;
    gesamtweite += weite;

    // Wert des ersten Sprungs als Startwert für min, max und max2 nehmen
    if (counter_sprung == 1)
    {
      min = weite;
      max = weite;
      max2 = weite;
    }
    
    // wenn weite kleiner als das Minimum ist: Minimum anpassen
    if (weite < min) 
    {
      min = weite;
    }

    // wenn weite größer als das Maximum ist: Maximum anpassen und das bisherige
    // maximum als zweitgrößten Wert nehmen
    else
    {
      if (weite > max){
        max2 = max;
        max = weite;
      }

      else
      {
        if (weite > max2) max2 = weite;
      }
    }
    
    printf("min: %lf\n", min);
    printf("max: %lf\n", max);
    printf("max2: %lf\n", max2);
  }

  durchschnitt = gesamtweite / counter_sprung;
  maxDifferenz = max - min;

  // Ausgabe der Ergebnisse
  printf("\nAnzahl der Sprünge: %d", counter_sprung);
  printf("\nweitester Sprung: %.2lf", max);
  printf("\nzweitweitester Sprung: %.2lf", max2);
  printf("\nkürzester Sprung: %.2lf", min);
  printf("\ndurchschnittliche Sprungweite: %.2lf", durchschnitt);
  printf("\nDifferenz zwischen max. und min. Weite: %.2lf\n", maxDifferenz);
  return 0;
}