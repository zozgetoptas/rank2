#include <unistd.h>
int	ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    while((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - 48);
        i++;
    }
    return (result * sign);
}
void ft_putnbr(int n)
{
    if (n < 0)
    {
        n *= -1;
        write(1, "-", 1);
    }
    if (n > 9)
        ft_putnbr(n / 10);
    char c = (n % 10) + 48;
    write(1, &c,1);
}
int is_prime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}
int main(int argc, char **argv)
{
    if (argc == 2 && ft_atoi(argv[1]) > 0)
    {
        int result = 0;
        int nbr = ft_atoi(argv[1]);
        while (nbr >= 2)
        {     
            if (is_prime(nbr) == 1)
                result += nbr;
            nbr--;
        }
        ft_putnbr(result);
    }
    else
        write(1, "0",1);
    write(1,"\n", 1);
}