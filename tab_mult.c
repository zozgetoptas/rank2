#include <unistd.h>
void	ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
void ft_putnbr(int nbr)
{
    if (nbr > 9)
        ft_putnbr(nbr / 10);
    char c = (nbr % 10) + 48;
    write(1, &c, 1);
}
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
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int nbr = ft_atoi(argv[1]);
        int i = 1;
        while(i <= 9)
        {
            ft_putnbr(i);
            ft_putstr(" x ");
            ft_putnbr(nbr);
            ft_putstr(" = ");
            ft_putnbr(i*nbr);
            write(1,"\n", 1);
            i++;
        }
    }
    else
        write(1,"\n", 1);
}