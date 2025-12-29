/*
Im Schach werden Züge durch Angabe der Felder notiert, von
und zu denen sie bewegt werden. Die Buchstaben a bis h werden
benutzt, um die senkrechten Spalten des Schachbretts zu be-
zeichnen, die Ziffern 1 bis 8 bezeichnen die horizontalen
Reihen. So steht der weiße König anfangs auf Feld e1.

a) Schreiben Sie eine Funktion, die feststellt, ob ein über-
gebenes Zeichen ein gültiger Buchstabe des Schachbretts ist.

b) Schreiben Sie eine Funktion, die feststellt, ob ein über-
gebenes Zeichen eine gültige Ziffer des Schachbretts ist.

c) Schreiben Sie eine Funktion, die feststellt, ob eine über-
gebene Zeichenkette eine gültige Feldbezeichnung ist! Eine
gültige Zeichenkette besteht aus zwei Zeichen. Das erste Zei-
chen ist ein Buchstabe, das zweite eine Ziffer gemäß der bei-
den obigen Funktionen.

d) Schreiben Sie ein Hauptprogramm, in dem der Benutzer
wiederholt Feldbezeichnungen des Schachbretts eingeben kann.
Geben Sie jeweils aus, ob die Eingabe gültig war oder nicht.
*/

#include <stdio.h>
#include <string.h>

/* Funktion für Aufgabe a
Funktion zum testen, ob der eingegebe Buchstabe auf dem
Schachbrett existiert */

int validLetter (char letter)
{
  char minBigLetter = 'A';
  char maxBigLetter = 'H';
  char minSmallLetter = 'a';
  char maxSmallLetter = 'h';

  if (
    (letter >= minBigLetter && letter <= maxBigLetter) || 
    (letter >= minSmallLetter && letter <= maxSmallLetter)
  )
    return 1;
    // wenn letter im erlaubten Bereich liegt: return true
  else
    return 0;
    // wenn letter außerhalb des Bereichs liegt: return false
}



/* Funktion für Aufgabe b
Funktion zum testen, ob die eingegebene Zahl zwischen 1
und 8 liegt */

int validNumber (char number)
{
  char minNumber = '1';
  char maxNumber = '8';

  if (number >= minNumber && number <= maxNumber)
    return 1;
  else
    return 0;
}


/* Funktion für Aufgabe c
Funktion zum testen, ob die übergebene Zeichenkette eine
gültige Feldbezeichnung ist */

int validString (char string[], int dim)
{
  char letter = string[0];
    // 1. Zeichen des Strings ist der Buchstabe
  char number = string[1];
    // 2. Zeichen des Strings ist die Zahl
  
  if (validLetter(letter) && validNumber(number))
    return 1;
  else
    return 0;
}


/* Hauptprogramm (für Aufgabe d) */
int main()
{
  // Erstellen der Zeichenkette
  //char input[3];
  char input[3];

/* Durchlauf des Programms, solange die Abbruchbedingung
nicht erfüllt ist */
  while (input[0] != 'q' && input[1] != 't')
  {
    // Abfrage einer Position auf dem Schachbrett
    printf("Position auf dem Schachbrett: ");
    
    // Einlesen der Zeichenkette
    scanf("%2s", &input);

    if (validString(input, 3))
      printf("Die eigegebene Position liegt auf dem Schachbrett.");
    else
      {
        printf("Die eingegebene Position liegt nicht auf dem ");
        printf("Spielfeld.");
      }
    printf("\n\n");
  }


  return 0;
}