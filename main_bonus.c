/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:56:56 by hojsong           #+#    #+#             */
/*   Updated: 2024/05/09 18:29:52 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
// #include "header/malloc3.h"
#include "header/malloc_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

char **strings;
int string_count = 0;
pthread_mutex_t mutex;

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
    while (i < 1000) {
        char *str = malloc(10 * (i + 1));
        pthread_mutex_lock(&mutex);
        if (str == NULL) {
            printf("Error: malloc failed\n");
            return NULL;
        }
        strings[string_count++] = str;
        pthread_mutex_unlock(&mutex);
		usleep(100);
		i++;
    }
    return NULL;
}

int main() {
    pthread_t threads[5];
    strings = malloc(sizeof(char *) * 5001);
	strings[5000] = NULL;
    pthread_mutex_init(&mutex, NULL);
	int	i;

	i = 0;
    while (i < 5){
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            printf("Error: thread creation failed\n");
            return 1;
        }
		i++;
    }

	i = 0;
    while (i < 5){
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Error: thread join failed\n");
            return 1;
        }
		i++;
    }
	show_alloc_mem();
	sleep(5);
    all_free(strings);
	show_alloc_mem_ex();
    pthread_mutex_destroy(&mutex);
    printf("All strings allocated and freed successfully\n");
    return 0;
}