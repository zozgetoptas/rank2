void	ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
#include <stdio.h>
int main()
{
    int a = 4, b = 97;
    printf("%d %d\n",a,b);
    ft_swap(&a,&b);
    printf("%d %d",a,b);
}