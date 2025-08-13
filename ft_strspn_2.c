#include <stddef.h>
size_t	ft_strspn(const char *s, const char *accept)
{
    size_t len = 0;
    while(*s)
    {
        char *temp_acc = accept;
        int match = 0;
        while(*temp_acc)
        {
            if (*s == *temp_acc)
            {
                match = 1;
                break;
            }
            temp_acc++;
        }
        if (match)
        {
            len++;
            s++;
        }
        else
            return len;
    }
    return len
}
