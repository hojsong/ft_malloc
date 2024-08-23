/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:56:56 by hojsong           #+#    #+#             */
/*   Updated: 2024/08/22 08:19:59 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
// #include "header/malloc_bonus3.h"
#include "header/malloc_bonus2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

char **strings;
int string_count = 0;
pthread_mutex_t mutex;
int maxsize = 1000;
int threadsize = 5;

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

void *thread_function(void *arg) {
	int i;

	arg = NULL;
	i = 0;
    while (i < maxsize) {
        char *str = malloc(10 * (i + 1));
        if (str == NULL) {
            printf("Error: malloc failed\n");
            return NULL;
        }
        pthread_mutex_lock(&mutex);
        strings[string_count++] = str;
        pthread_mutex_unlock(&mutex);
		i++;
    }
    return NULL;
}

int main() {
    threadsize = 5;
    pthread_t threads[5];
    strings = malloc(sizeof(char *) * ((maxsize * threadsize) +1));
	strings[(maxsize * threadsize)] = NULL;
    pthread_mutex_init(&mutex, NULL);
	int	i;

	i = 0;
    while (i < threadsize){
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            printf("Error: thread creation failed\n");
            return 1;
        }
		i++;
    }

    sleep(2);

	i = 0;
    while (i < threadsize){
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Error: thread join failed\n");
            return 1;
        }
		i++;
    }
	show_alloc_mem();
	sleep(3);
    all_free(strings);
	show_alloc_mem_ex();
    pthread_mutex_destroy(&mutex);
    printf("All strings allocated and freed successfully\n");
    return 0;
}