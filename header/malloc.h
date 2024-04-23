/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:41:01 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/22 07:20:54 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include <sys/resource.h>
# include <stdio.h>

# define TINY_SIZE	 128
# define SMALL_SIZE  4096

typedef struct m_struct{
	void			*ptr;
	size_t			size;
	size_t			max_size;
	int				*si;
	struct m_struct	*next;
}	t_st;

typedef struct m_structa{
	struct m_struct		*tiny;
	struct m_struct		*small;
	struct m_struct		*large;
	struct m_structa	*next;
}	t_sta;

void	*malloc(size_t size);
void	free(void *ptr);
void	*realloc(void *ptr, size_t size);
void	show_alloc_mem(void);

t_st	*t_stinit(t_st *src, size_t size);
t_st	*size_of_return(size_t size);
void	*find_mem(t_st *src, size_t size);
int		findof_ptr_free(void *ptr, t_st *src, char *str);
void	lst_si_init(t_st *src, size_t size);

void	*fail_map(t_st *src);
void	print_of_easy(int fd, t_st *src, size_t idx, size_t size);
size_t	easy_print(int fd, t_st *src);
size_t	put_ptr_fd(int fd, t_st *ptr);
size_t	resize(size_t size);

void    init(void);
t_st    *newLarge(size_t size);

void	m_ft_replace(void *ptr, t_st *src, t_st *dest, char *str);
t_st	*newlst(size_t size);
t_st	*large(size_t size);

int		m_ft_strcmp(char *str1, char *str2);
void	put_hex_num(int fd, unsigned long long ptr, int idx);
size_t	m_ft_strlen(char *str);
void	put_str_fd(int fd, char *str);
void	put_num_fd(int fd, size_t num);

#endif