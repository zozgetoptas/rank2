#include <stdlib.h>
int digit_count(int nbr)
{
    int count = 0;
    if (nbr < 0)
    {
        count++;
        nbr *= -1;
    }
    else if (nbr == 0)
        return 0;
    while(nbr > 0)
    {
        count++;
        nbr /= 10;
    }
    return count;
}

char	*ft_itoa(int nbr)
{
    char *result = malloc(digit_count(nbr) + 1);
    int i = digit_count(nbr) - 1;
    result[digit_count(nbr)] = '\0';
    while(i >= 0)
    {
        char c = (nbr % 10) + 48; 
        result[i] = c;
        i--;
        nbr /= 10;
    }
    return result;
}
#include <stdio.h>
int main()
{
    char *result = ft_itoa(23);
    printf("%s", result);
}