#include <stdio.h>
#include <string.h>
char	*ft_strpbrk(const char *s1, const char *s2)
{
    while(*s1)
    {
        const char *temp = s2;
        while(*temp)
        {
            if(*s1 == *temp)
                return ((char *)s1);
            temp++;
        }
        s1++;
    }
    return NULL;
}
int main()
{
    char s1[] = "zozge";
    char s2[] = "hjk";
    char *ret1 =ft_strpbrk(s1,s2);
    char *ret2 = strpbrk(s1,s2);
    printf("%s\n", ret1);
    printf("%s\n", ret2);
} 