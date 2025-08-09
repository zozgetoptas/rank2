#include <stddef.h>
size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t len = 0;
    while(*s)
    {
        const char *temp_rej = reject;
        while(*temp_rej)
        {
            if (*s == *temp_rej)
                return len;
            temp_rej++;
        }
        s++;
        len++;
    }
    return len;
}
#include <string.h>
#include <stdio.h>
int main()
{
    char s[] = "zozge";
    char rej[] = "abce";
    printf("%zu\n",ft_strcspn(s,rej));
    printf("%zu\n",strcspn(s,rej));
    
}