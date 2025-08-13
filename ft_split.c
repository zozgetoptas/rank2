#include <stdlib.h>
static int count_words(char *str)
{
    int i = 0;
    int count = 0;
    int in_word = 0;

    while (str[i])
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            in_word = 0;
        }
        else if (in_word == 0)
        {
            in_word = 1;
            count++;
        }
        i++;
    }
    return count;
}

char **ft_split(char *str)
{
    char **splitted;
    int word_count;
    int i = 0;
    int j = 0;
    int k = 0;
    int word_len;
    int word_start;

    if (!str)
        return NULL;
    word_count = count_words(str);
    splitted = malloc(sizeof(char *) * (word_count + 1));
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        if (str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
        {
            word_start = i;
            word_len = 0;
            while (str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            {
                word_len++;
                i++;
            }
            splitted[j] = malloc(sizeof(char) * (word_len + 1));
            k = 0;
            while (k < word_len)
            {
                splitted[j][k] = str[word_start + k];
                k++;
            }
            splitted[j][k] = '\0';
            j++;
        }
    }
    splitted[j] = NULL;
    return splitted;
}

#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str); // ft_split fonksiyonunun prototipi

int main()
{
    char str[] = "  z  ozge \t toptas  ";
    int i = 0;
    char **res = ft_split(str);
    if (res)
    {
        while(res[i] != NULL)
        {
            printf("Kelime %d: [%s]\n", i, res[i]);
            i++;
        }
    }
    else
    {
        printf("Hata: ft_split NULL dondurdu.\n");
    }

    // Bellek sızıntısını önlemek için ayrılan belleği temizle
    if (res)
    {
        i = 0;
        while(res[i] != NULL)
        {
            free(res[i]);
            i++;
        }
        free(res);
    }
    return 0;
}