#include <stddef.h>
#include <string.h>
#include <stdio.h>
size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int len = 0;
    while(s[i])
    {
        int j = 0;
        while(reject[j])
        {
            if (s[i] == reject[j])
                return len;
            j++;
        }
        i++;
        len++;
    }
    return len;
}
int main()
{
    char s1[] = "zozgetoptas";
    char s2[] = "abcde";
    printf("%zu\n", ft_strcspn(s1,s2));
    printf("%zu",strcspn(s1,s2));
}