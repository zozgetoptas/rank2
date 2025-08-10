unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int multiple;
    
    int i = 2;
    if (a == b)
        return a;
    if (a == 0 || b == 0)
		return (0);
    if (a == 1)
        return b;
    if (b == 1)
        return a;
    if (a > b)
        multiple = a;
    else
        multiple = b;
    while(1)
    {
        if (multiple % a == 0 && multiple % b == 0)
            return multiple;
        multiple++;
    }
}
#include <stdio.h>
int main()
{
    printf("%d",lcm(0,1));
}