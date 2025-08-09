#include <stddef.h>
size_t	ft_strspn(const char *s, const char *accept)
{
    size_t len = 0;
    while(*s)
    {
        int match = 0;
        const char *temp_accept = accept;
        while (*temp_accept)
        {
            if (*s == *temp_accept)
            {
                match = 1;
                break;
            }
            temp_accept++;
        }
        if (match)
        {
            len++;
            s++;
        }
        else
            return len;
    }
    return len;
}
#include <string.h>
#include <stdio.h>
int main()
{
    char s[] = "zozgetoptas";
    char accept[] = "asedozfghj";
    printf("%zu\n",ft_strspn(s,accept));
    printf("%zu\n",strspn(s,accept));
}