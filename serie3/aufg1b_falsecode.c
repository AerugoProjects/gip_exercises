int main() 
// #include <stdio.h> fehlt
{
    int n, i, q;
    printf("Geben Sie eine positive ganze Zahl ein: ); 
        // Anführungszeichen müssen geschlossen werden
    scanf("%d", &n);
    0 = q; 
        // die Variable muss der Zahl zugeorndet werden, nicht andersherum
    for (i = n; i > 0; i = i / 10)
        q = q + (i % 10) 
            // Semikolon am Zeilenende fehlt
    printf("Die Quersumme von %d ist: %d\n", n q);
        // zwischen n und q fehlt ein Komma
    return 0;
}