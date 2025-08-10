int		max(int* tab, unsigned int len)
{
    int i = 0;
    if (len == 0)
        return 0;
    int ret = tab[0];
    while(i < len)
    {

        if (tab[i] > ret)
            ret = tab[i];
        i++;
    }
    return ret;
}
#include <stdio.h>
int main()
{
    int arr[4] = {186,15,4,1};
    max(arr,4);
    printf("%d", max(arr,4));
}