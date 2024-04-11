#ifndef _FT_MALLOC_H_
# define _FT_MALLOC_H_

#include <sys/mman.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdio.h>

typedef struct m_struct{
    void            *ptr;
    size_t          size;
    size_t          max_size;
    int             *si;
    struct m_struct *next;
} t_st;

typedef struct m_structa{
    struct m_struct    *tiny;
    struct m_struct    *small;
    struct m_struct    *large;
    struct m_structa    *next;
} t_sta;

void    *ft_malloc(size_t size);
void    ft_free(void *ptr);
void    *ft_realloc(void *ptr, size_t size);
void    show_alloc_mem();

void    ft_replace(void *ptr, t_st *src, t_st *dest, char *str);
t_st    *newlst(size_t size);
t_st    *large(size_t size);

int     ft_strcmp(char *str1, char *str2);
void    put_hex_num(int fd, unsigned long long ptr, int idx);
void    put_ptr_fd(int fd, t_st *ptr);
size_t  ft_strlen(char *str);
void    put_str_fd(int fd, char *str);
void    put_num_fd(int fd, size_t num);

#endif