unsigned char	reverse_bits(unsigned char octet)
{
    int i = 7;
    int result = 0;
    while(i >= 0)
    {
        result = (result * 2) + (octet %2);
        octet /= 2;
        i--;
    } 
    return result;
}
#include <stdio.h>
int main()
{
    unsigned char octet = 2;
    unsigned char new = reverse_bits(octet);
    printf("%d",new);
}