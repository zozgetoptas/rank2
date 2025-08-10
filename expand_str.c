#include <unistd.h>
int main(int argc, char **argv)
{
    int i = 0;
    int first = 1;
    if (argc == 2)
    {
        while((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i])
                i++;
        while(argv[1][i])
        {
            if (argv[1][i] == '\t' || argv[1][i] == ' ')
            {
                while (argv[1][i] == '\t' || argv[1][i] == ' ')
                    i++;
                if (argv[1][i] && first == 0)
                    write(1, "   ", 3);
            }
            else
            {
                write(1, &argv[1][i], 1);
                first = 0;
                i++;
            }
        }
    }
    write(1, "\n",1);
}