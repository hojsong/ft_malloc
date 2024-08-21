/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:41:01 by hojsong           #+#    #+#             */
/*   Updated: 2024/05/24 20:18:04 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_BONUS_H
# define MALLOC_BONUS_H

# include <sys/mman.h>
# include <unistd.h>
# include <sys/resource.h>
# include <stdio.h>
# include <pthread.h>
# include <time.h>

# define TINY_SIZE	 128
# define SMALL_SIZE  2048
# define TINY_PAGE	 4
# define SMALL_PAGE  21

typedef struct m_struct{
	void			*ptr;
	size_t			size;
	unsigned char	*si;
	struct m_struct	*next;
}	t_st;

typedef struct m_stack{
	void				*ptr;
	size_t				size;
	char				*start_time;
	char				*end_time;
	struct m_stack		*next;
}	t_stack;

// typedef struct m_stack{
// 	unsigned long long	ptr;
// 	size_t				size;
// 	time_t				start_time;
// 	time_t				end_time;
// 	struct m_stack		*next;
// }	t_stack;

typedef struct m_structa{
	struct m_struct		*tiny;
	struct m_struct		*small;
	struct m_struct		*large;
	struct m_stack      *g_stack;
	size_t				stack_size;
}	t_sta;

t_sta			*g_all;
pthread_mutex_t	g_gardner;

void	init_lcok(void);
void    free_lst(void *ptr);
void    malloc_lst(void *ptr, size_t size);
void	*malloc(size_t size);
void	free(void *ptr);
void	*realloc(void *ptr, size_t size);
void    show_alloc_mem(void);
void    show_alloc_mem_ex(void);

void	put_hex_num(int fd, unsigned long long ptr, int idx);
void	put_str_fd(int fd, char *str);
void	put_num_fd(int fd, size_t num);
size_t	m_ft_strlen(char *str);
size_t	resize(size_t size, size_t x);
t_st	*size_of_return(size_t size);
int		m_ft_strcmp(char *str1, char *str2);
size_t	get_size(void *ptr);
size_t	return_size(t_st *x, size_t idx);

#endif