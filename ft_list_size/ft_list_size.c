#include "ft_list.h"
int	ft_list_size(t_list *begin_list)
{
    int i = 0;
    while(begin_list)
    {
        begin_list = begin_list->next;
        i += 1;
    }
    return i;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
    t_list *node1;
    t_list *node2;
    t_list *node3;
    node1 = (t_list *)malloc(sizeof(t_list));
    node2 = (t_list *)malloc(sizeof(t_list));
    node3 = (t_list *)malloc(sizeof(t_list));
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1->data = "z";
    node2->data = "ozge";
    node3->data = "toptas";
    printf("%d", ft_list_size(node1));
}