#include <stdio.h>

int main()
{
    int tc, tf; 
    printf("Geben Sie eine ganze Zahl gößer gleich Null ein: ");
    scanf("%d", &tf);
    tc = (5 * (tf - 32)) / 9;
    printf("%d in Fahrenheit beträgt %d in Grad Celsius, ", tf, tc);
    return 0;
}