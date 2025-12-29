/*
Implementieren Sie die folgenden Funktionen für Zeichenketten
mit Hilfe von Zeigern und Zeigearithmetik in der Sprache C:

a) int stringLen(char *str) bekommt eine Zeichenkette und
gibt deren Länge zurück.

b) int stringCount(char c, char *str) zählt das Vorkommen
eines Zeichens in einer Zeichenkette und gibt die Anzahl
zurück.

c) char* stringCat(char *str1, char *str2) bekommt zwei
Zeichenketten, hängt diese aneinander und gibt die verbundene
Zeichenkette zurück. Hinweis: Diese Funktion muss für die
resultierende Zeichenkette ausreichend Speicher allozieren.

Schreiben Sie zudem ein Hauptprogramm, in dem der Nutzer
zwei Zeichenketten eingeben kann, die dann zum Testen der
obigen Funktionen genutzt werden.

Die Funktionen aus der Standardbibliothek string.h sollen
dabei nicht verwendet werden!
*/

/* scanf( "%24[^\n]", str)
- ignores all whitespace characters and scan max 24 charactres
  until a \n and store it in str
- quelle: https://stackoverflow.com/questions/35103745/read-a-string-as-an-input-using-scanf
*/

#include <stdio.h>

/* Augabenteil a
Länge einer Zeichenkette bestimmen */
int stringLen (char *string)
{
  int counterStingLen;
  // counter für die Zeichenanzahl

  int temp = 0;
  while (*(string+temp) != '\0')
  {
    temp++;
    counterStingLen++;
  }

  return counterStingLen;
}