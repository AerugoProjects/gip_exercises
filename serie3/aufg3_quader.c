#include <stdio.h>

int main()
{
    // einzugebende Koordinaten
    int x1, x2, y1, y2, z1, z2;
    // Länge der einzelnen Kanten (wird berechnet)
    int dx, dy, dz;
    // Volumen, Gesamtfläche und Gesamtkantenlänge (wird berechnet)
    int volumen, flaeche, laenge;

    // Einlesen der Koodinaten der Ecke unten links
    printf("Verwenden Sie bitte folgendes Eingabeformat: x y z und bestätigen Sie mit 'Enter'.\n");
    printf("Geben sie die drei Koordinaten der unteren, linken Ecke an: ");
    scanf("%d %d %d", &x1, &y1, &z1);

    // Einlesen der Koodinaten der Ecke oben rechts
    printf("Geben sie die drei Koordinaten der oberen, rechten Ecke an: ");
    scanf("%d %d %d", &x2, &y2, &z2);


    // Berechnung der einzelnen Kantenlängen
    dx = x2 - x1; dy = y2 - y1; dz = z2 - z1;

    // Berechnung der Gesamtkantenlänge
    laenge = 4 * (dx + dy + dz);

    // Berechnung der Gesamtfläche
    flaeche = 2 * ((dx * dy) + (dy * dz) + (dx * dz));

    // Berechnung des Volumens
    volumen = dx * dy * dz;

    // Ausgabe der Ergebnisse
    printf("Der Quader hat; \n eine Kantenlänge von %d unit, \n eine Oberfläche von %d square unit \n und ein Volumen von %d cubic unit. ", laenge, flaeche, volumen);
}