#include <stdlib.h>

// Bu fonksiyon, boşluk, tab (\t) ve yeni satır (\n) karakterlerini kontrol eder.
static int is_delimiter(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

// Bu fonksiyon, bir stringdeki kelime sayısını sayar.
static int count_words(char *str)
{
    int i = 0;
    int count = 0;
    int in_word = 0;

    while (str[i])
    {
        if (is_delimiter(str[i]))
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
    if (!splitted)
        return NULL;

    while (str[i])
    {
        // Delimiterları atla
        while (str[i] && is_delimiter(str[i]))
            i++;
        
        // Bir kelime bulduğunda
        if (str[i] && !is_delimiter(str[i]))
        {
            word_start = i;
            word_len = 0;
            while (str[i] && !is_delimiter(str[i]))
            {
                word_len++;
                i++;
            }

            // Kelime için bellek tahsisi yap ve kopyala
            splitted[j] = malloc(sizeof(char) * (word_len + 1));
            if (!splitted[j])
            {
                // Hata durumunda önceden ayrılan belleği temizle
                while (j > 0)
                {
                    j--;
                    free(splitted[j]);
                }
                free(splitted);
                return NULL;
            }

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