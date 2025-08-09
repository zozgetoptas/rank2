#include <stdio.h>
#include <string.h>
char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while(s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}
int main()
{
    char mine[6];
    char ori[6];
    char s[] = "zozge";
    printf("%s",ft_strcpy(mine,s));
    printf("%s",strcpy(ori,s));
}