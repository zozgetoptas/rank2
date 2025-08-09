#include "do_op.h"
int main(int argc, char **argv)
{
    if (argc == 4)
    {
        int result;
        if (argv[2][0] == '+')
            result = atoi(argv[1]) + atoi(argv[3]);
        else if (argv[2][0] == '-')
            result = atoi(argv[1]) - atoi(argv[3]);
        else if (argv[2][0] == '*')
            result = atoi(argv[1]) * atoi(argv[3]);
        else if (argv[2][0] == '/')
            result = atoi(argv[1]) / atoi(argv[3]);
        else if (argv[2][0] == '%')
            result = atoi(argv[1]) % atoi(argv[3]);
        printf("%d",result);
    }
    printf("\n");
}