char    *ft_strrev(char *str)
{
    int i = 0;
    int len = 0;
    while(str[len])
        len++;
    char temp;
    while(i < len / 2)
    {
        temp = str[i];
        str[i] = str[len - i -1];
        str[len - i -1] = temp;
        i++;
    }
    return str;
}
#include <stdio.h>
int main()
{
    char str[] = "ozge";
    printf("%s", ft_strrev(str));
}