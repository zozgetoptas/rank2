#include <unistd.h>
void print_nbr(int i)
{
    if(i > 9)
        print_nbr(i / 10);
    char c = (i % 10) + 48;
    write(1, &c, 1);
}
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    int i = 1;
    while(i <= 100)
    {
        if (i % 15 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else
            print_nbr(i);
        write(1, "\n", 1);
        i++;
    }
}