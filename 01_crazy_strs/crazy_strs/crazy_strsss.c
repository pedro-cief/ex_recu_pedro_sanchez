#include <unistd.h>


int minus(char *str)
{
    int i;

    i = 0;
    while (str[i] >= 'a' && str[i] <= 'z')
    {
        if (str[i] == '-')
            i++;
        else
            break;
    }
    return (i);
}

int mayus(char *str)
{
    int i;

    i = 0;
    while (str[i] >= 'A' && str[i] <= 'Z')
    {
        if (str[i] == '+')
            i++;
        else
            break;
    }
    return (i);
}


int str_len(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int found_space(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            i++;
        else
            break;
    }
    return (i);
}

int found_space_rev(char *str, int start)
{
    int i;

    i = str_len(str) - 1;
    while (i > start)
    {
        if (str[i] == ' ')
            i--;
        else
            break;
    }
    return (i);
}

int main(int argc, char **argv)
{
    int i;
    int finish;
    int start;

    if (argc >= 3)
    {
        i = 1;
        while (i < argc)
        {
            if (argv[i])
            {
                if (i % 3 == 0)
                {
                    start = found_space(argv[i]);
                    finish = found_space_rev(argv[i], start);
                    while (finish >= start)
                    {
                        write(1, &argv[i][finish], 1);
                        finish--;
                    }
                }
                else
                {
                    start = found_space(argv[i]);
                    finish = found_space_rev(argv[i], start);
                    while (start <= finish)
                    {
                        write(1, &argv[i][start], 1);
                        start++;
                    }
                }
                write(1, "\n", 1);
            }
            else
                break;
            i++;
        }
    }
    else
        write(2, "Argument Error\n", 16);
    return (0);
}