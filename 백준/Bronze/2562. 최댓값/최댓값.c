#include <stdio.h>

int main()
{
    int num[10];
    for (int i = 1; i <= 9; i++)
        scanf("%d", &num[i]);
    int Max = num[1];
    int n = 1;
    for ( int i = 1; i <=9; i++)
    {
        if (num[i]>Max)
        {
            Max = num[i];
            n = i;
        }
    }
    printf("%d\n%d\n", Max, n);
    return 0;
}