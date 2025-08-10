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
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int result = 0;
        int nbr = ft_atoi(argv[1]);
        if (nbr == 0)
            write(1, "0", 1);
        char digits[] = "0123456789abcdef";
        char buffer[8]; 
        int i = 0;
        while(nbr > 0)
        {

            buffer[i] = digits[nbr % 16];
            nbr /= 16;
            i++;
        }

            i--;
            while(i >= 0)
            {
                write(1, &buffer[i],1);
                i--;
            }
        }
    write(1,"\n",1);
}