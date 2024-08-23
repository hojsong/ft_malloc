#include "libft/libft.h"
#include "header/malloc3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

// char **strings;
// int string_count = 0;
// pthread_mutex_t mutex;
// int maxsize = 1000;
// int threadsize = 5;

void	all_free(char **str)
{
	size_t i;
	i = 0;

	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

// int main()
// {
//     char **str;
//     int x, y;

//     y = 10000;
//     str = malloc(sizeof(char *) * (y + 1));
//     str[y] = NULL;
//     x = 0;
//     while (x < y)
//     {
//         str[x] = malloc(sizeof(char) * ((x + 1) * 10));
//         x++;
//     }
//     show_alloc_mem();
// }

//2

int main()
{
    char **str;
    int x, y;

    y = 100;
    x = 0;
    str = malloc(sizeof(char *) * 101);
    str[y] = NULL;
    while (x < y)
    {
        str[x] = malloc(128);
        x++;
    }
    show_alloc_mem();
    str[y] = NULL;
    x = 0;
    while (x < y)
    {
        free(str[x]);
        str[x] = malloc(2048);
        x++;
    }
    show_alloc_mem();
    all_free(str);
    show_alloc_mem();
}