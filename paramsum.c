#include <unistd.h>
void ft_putnbr(int nbr)
{
    if (nbr > 9)
        ft_putnbr(nbr / 10);
    char c = (nbr % 10) + 48;
    write(1, &c, 1);
}
int main(int argc, char **argv)
{
    if (argc > 1)
    {
        int i = 1;
        while(argv[i])
        {
            i++;
        }
        ft_putnbr(i - 1);
    }
    else
        ft_putnbr(0);
    write(1, "\n", 1);
}