#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int first = 0;
    if (argc == 2)
    {
        int nbr = atoi(argv[1]);
        int d = 2;
        if (nbr = 1)
            printf("1");
        while (d <= atoi(argv[1]))
        {
            while ((nbr % d == 0))
            {
                if (first == 0)
                {
                    printf("%d",d);
                    nbr /= d;
                    first = 1;
                }
                else
                {
                    printf("*%d",d);
                    nbr /= d;
                }
            }
            d++;
        }
    }
    printf("\n");
}