#include <stdio.h>

int main()
{
    int n,f;
    printf("Geben Sie eine positive ganze Zahl ein: ");
    scanf("%d", &n);
    printf("Die Fakultaet von %d ist: ", n);
    f = 1;
    while (n > 0)
        {
        f = f * n;
        n = n - 1;
        }
    printf("%d\n", f);
    return 0;
}