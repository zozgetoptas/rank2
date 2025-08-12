typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
#include <stdlib.h>
#include <string.h>

int cmp(void *first, void *second)
{
    return strcmp((char *)first, (char *)second);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
    t_list *temp;
    t_list **ptr;

    ptr = begin_list;
    while (*ptr)
    {
        if (cmp((*ptr)->data, data_ref) == 0)
        {
            temp = *ptr;
            *ptr = temp->next;
            free(temp);
        }
        else
        {
            ptr = &(*ptr)->next;
        }
    }
}