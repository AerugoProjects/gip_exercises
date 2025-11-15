#include <stdio.h>

int main()
{
    int n, i, q;
    printf("Geben Sie eine positive ganze Zahl ein: ");
    scanf("%d", &n);
    q = 0;
    for (i = n; i > 0; i = i / 10)
        q = q + (i % 10);
    printf("Die Quersumme von %d ist: %d\n", n, q);
    return 0;
}