#include <unistd.h>
void	print_bits(unsigned char octet)
{
    int i = 7;
    unsigned char bit;
    while (i >= 0)
    {
        bit = (octet >> i) & 1; 
        if (bit == 1)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        i--;
    }
}
int main()
{
    print_bits(5);
}