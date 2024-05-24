/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:41:01 by hojsong           #+#    #+#             */
/*   Updated: 2024/05/24 20:18:52 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include <sys/resource.h>
# include <stdio.h>

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

typedef struct m_structa{
	struct m_struct		*tiny;
	struct m_struct		*small;
	struct m_struct		*large;
	struct m_structa	*next;
}	t_sta;

void	*malloc(size_t size);
void	free(void *ptr);
void	*realloc(void *ptr, size_t size);
void    show_alloc_mem(void);

void	put_str_fd(int fd, char *str);
void	put_num_fd(int fd, size_t num);
size_t	m_ft_strlen(char *str);
size_t	resize(size_t size, size_t x);
t_st	*size_of_return(size_t size);
int		m_ft_strcmp(char *str1, char *str2);
size_t	get_size(void *ptr);
size_t	return_size(t_st *x, size_t idx);


#endif