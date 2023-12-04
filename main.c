#include "shell.h"
/**
 * main - this is the main code of the shell project
 * Return: 0 most probably
*/
int main(int ac, char **av)
{
        int position;
        char *input = NULL;
        char **buffer = NULL;
        (void)ac;

        position = 0;

        while (1)
        {
            input = read_line();
            if (input == NULL)
            {
                return (position);
            }
            buffer = split_token(input);
            position = _implement(buffer, av);
        }
}
