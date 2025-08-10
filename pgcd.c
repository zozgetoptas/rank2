#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int max = 1;
        int d = 2;
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        if (a == 1 || b == 1)
            printf("1");
        else
        {
            while (d <= a && d <= b)
            {
                if (a % d == 0 && b % d == 0)
                    max = d;
                d++;
            }
            printf("%d",max);
        }
    }
    printf("\n");
}