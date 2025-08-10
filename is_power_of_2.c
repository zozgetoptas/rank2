int	    is_power_of_2(unsigned int n)
{
    while ((n % 2 == 0) && n > 1)
    {
        n /= 2;
    }
    if (n == 1)
        return 1;
    return 0;
}
#include <stdio.h>
int main()
{
    printf("%d\n",is_power_of_2(1));
    printf("%d\n",is_power_of_2(3));
    printf("%d\n",is_power_of_2(128));
    printf("%d\n",is_power_of_2(0));
}