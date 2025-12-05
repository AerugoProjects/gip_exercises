/*
In dieser Aufgabe sollen Sie die Umwandlung zwischen Binärzahlen und Dezimal-
zahlen in C realisieren. Implementieren Sie dazu eine Funktion binaryToDecimal, 
die als Parameter eine Binärzahl in Form einer ganzen Zahl n >= 0 erhält, die 
zugehörige Dezimalzahl bestimmt und zurückgibt. 
Eine weitere Funktion decimalToBinary soll die umgekehrte Richtung implementieren. 
Eine als Parameter übergebene ganze Dezimalzahl n >= 0 soll dazu in eine Binärzahl 
umgewandelt und zurückgeben werden.
Testen Sie beide Funktionen in einem passenden Hauptprogramm!
*/

#include <stdio.h>
#include <math.h>


int binaryToDecimal(int binary)
{
  int maxBinaryDigit;
    // maximale Anzahl an Stellen
  int i = 0;
    // Laufvariable für die aktuelle Stelle
  int n = 0;
    // Laufvariable für die 2er-Potenz
  int decimal = 0;
    // Dezimalform
  
  maxBinaryDigit = log10(binary);
    // bestimmt die Anzahl an Ziffern der Binärzahl

  for (i=binary; i>0 && n <= maxBinaryDigit; i=i/10, n+=1)
  {
    //printf("decimal: %d \n i: %d \n n: %d\n", decimal,i,n);
    decimal = decimal + (i%10) * pow(2,n);
  }

  return decimal;
}


int decimalToBinary(int decimal)
{
  int i = decimal;
    // Laufvariable für die aktuelle Stelle
  int binary = 0;
    // Binärdarstellung
  int digit = 0;
    // 0 oder 1 an der jeweiligen Stelle
  int maxPot = log2(decimal);
    // bestimmt die maximale 2er Potenz
  int binaryArray[maxPot+1];
    // Binärform
  int pot = maxPot;
    // Laufvariable für die 2er Potenz
    
  // binary-Werte auf 0 setzen
  for (int temp = 0; temp < maxPot+1; temp++)
    binaryArray[temp] = 0;

  for (;pot >= 0;)
  {
    int potNumber = pow(2.0,(double)pot);
    digit = i/potNumber;
    binaryArray[maxPot-pot] = digit;
    //printf("\n\npotNumber %d \npot %d \ndigit %d \ni %d\n", potNumber, pot,digit,i);
    //printIntArray(binaryArray,maxPot+1);
    i = i-potNumber*digit;
    pot -= 1;
  }

  for (int temp = 0; temp < maxPot+1; temp++)
  {
    binary = binary + binaryArray[temp]*pow(10.0,(maxPot-(double)temp));
  }
  return binary;
}


void printIntArray(int array[], int dim)
{
  for (int i = 0; i < dim; i++)
  {
    printf("index %d ",i);
    printf("%d ",array[i]);
  }
  printf("\n");
}


int main(void)
{
  int numberBinary = 0;
    // umgewandelte Zahl in binär-Darstellung
  int numberDecimal = 0;
    // umgewandelte Zahl in decimal-Darstllung
  int numberTest = 0;
    // zu testende Nummer
  int typeNumber = 2;
    // notwendig für die Auswahl, welche in welchen Darstellungstyp numberTest
    // umgewandelt werden soll
  
  while (typeNumber != 0 && typeNumber !=1)
  {
    printf("0 -- eingegebene Zahl ist eine Binärzahl\n");
    printf("1-- eingegebene Zahl ist eine Dezimalzahl\n");
    printf("Bitte geben Sie eine Zahl und deren Typ (0 oder 1) ein: ");
      // Abfragen einer Zahl
    scanf("%d %d",&numberTest, &typeNumber);
      // Einlesen der Binärzahl
  }

  if (typeNumber == 0)
  {
    numberDecimal = binaryToDecimal(numberTest);
      // Umwandlung der Binärdarstellung in Decimaldarstellung mit der Funktion
      // binaryToDecimal
    printf("eingegebene Zahl (Binärdarstellung): %d\n", numberTest);
      // Ausgabe der eingelesenen Binärzahl
    printf("\t  Zahl in Dezimaldarstellung: %d\n\n", numberDecimal);
      // Ausgabe der Zahl in decimal Darstellung
  }
  else
  {
    numberBinary = decimalToBinary(numberTest);
      // Umwandlung der Decimaldarstellung in Binärdarstellung mit der Funktion
      // decimalToBinary
    int maxPot = log2(numberTest);
    printf("eingegebene Zahl (Dezimaldarstellung): %d\n", numberTest);
      // Ausgabe der eingelesenen Binärzahl
    printf("\t     Zahl in Binärdarstellung: %d\n\n", numberBinary);
  }
    

  return 0;
}