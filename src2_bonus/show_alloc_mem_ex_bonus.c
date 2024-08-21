/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_ex_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:01:42 by hojsong           #+#    #+#             */
/*   Updated: 2024/06/02 04:37:59 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc_bonus.h"

void    stack_dup(char *str, char *str2)
{
    size_t  x;

    x = 0;
    while (str && str2 && str2[x])
    {
        str[x] = str2[x];
        x++;
    }
    str[x] = '\0';
}

t_stack *new_stack_one(void *ptr, size_t idx, size_t src_size, size_t time_size)
{
    t_stack *result;

    result = &ptr[(idx * src_size) + ((idx * 2) * time_size)];
    result->ptr = 0;
    result->size = 0;
    result->start_time = &ptr[((idx + 1) * src_size) + ((idx * 2) * time_size)];
    result->start_time[0] = '\0';
    result->end_time = &ptr[((idx + 1) * src_size) + (((idx * 2) + 1) * time_size)];
    result->end_time[0] = '\0';
    result->next = NULL;

    return (result);
}

void    stack_add_back(t_stack *stack)
{
    t_stack *src;
    t_stack *dest;

    if (g_all->g_stack == NULL)
    {
        g_all->g_stack = stack;
        return ;
    }
    src = g_all->g_stack;
    while(src)
    {
        if (src->next == NULL)
            break ;
        dest = src->next;
        src = dest;
    }
    src->next = stack;
}

void    new_stack(void *ptr, size_t size)
{
    t_stack *stack;
    t_stack *src;
    t_stack *dest;
    void    *m_ptr;
    size_t  idx;
    time_t  t;
    size_t  ssize;
    char    *str;
    
    if (ptr == NULL)
        return ;
    m_ptr = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    while (m_ptr == NULL || m_ptr == MAP_FAILED)
    {
        m_ptr = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, \
		    MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    }
    t = time(NULL);
    while (t == -1)
        t = time(NULL);
    str = ctime(&t);
    while (str == NULL)
        str = ctime(&t);
    ssize = m_ft_strlen(str);
    stack = new_stack_one(m_ptr, 0, sizeof(t_stack), ssize);
    while (stack->ptr != ptr)
        stack->ptr = ptr;
    stack->size = size;
    str[ssize - 1] = '\0';
    stack_dup(stack->start_time, str);
    idx = 1;
    dest = stack;
    while (((idx + 1) * sizeof(t_stack)) + (((idx + 1) * 2) * ssize) < (size_t)getpagesize())
    {
        src = NULL;
        src = new_stack_one(m_ptr, idx, sizeof(t_stack), ssize);
        while (src->ptr != 0)
            src->ptr = 0;
        while (src->next != NULL)
            src->next = NULL;
        dest->next = src;
        dest = src;
        idx++;
    }
    g_all->stack_size += idx;
    dest->next = NULL;
    stack_add_back(stack);
}

//malloc success
void    malloc_lst(void *ptr, size_t size)
{
    t_stack *src;
    t_stack *dest;
    time_t  t;
    char    *str;
    
    if (g_all->g_stack)
    {
        src = g_all->g_stack;
        while (src && g_all->g_stack)
        {
            if(src->size == 0 && src->ptr == 0)
            {
                src->ptr = ptr;
                src->size = size;
                t = time(NULL);
                while (t == -1)
                    t = time(NULL);
                str = ctime(&t);
                while (str == NULL)
                    str = ctime(&t);
                str[m_ft_strlen(str) - 1] = '\0';
                stack_dup(src->start_time, str);
                return ;
            }
            if (src->next == NULL)
                break;
            dest = src->next;
            src = dest;        
        }
    }
    new_stack(ptr, size);
}

// free success
void    free_lst(void   *ptr)
{
    t_stack *src;
    t_stack *dest;
    time_t  t;
    char    *str;
    
    src = g_all->g_stack;
    while (src)
    {
        if(src->ptr == ptr && src->end_time[0] == '\0')
        {
            t = time(NULL);
            while (t == -1)
                t = time(NULL);
            str = ctime(&t);
            while (str == NULL)
                str = ctime(&t);
            str[m_ft_strlen(str) - 1] = '\0';
            stack_dup(src->end_time, str);
            return ;
        }
        if (src->next == NULL)
            break;
        dest = src->next;
        src = dest;        
    }
}

void    print_show_ptr(t_stack *src)
{
    put_hex_num(1, (unsigned long long)src->ptr, 0);
    write (1, " - ", 3);
    put_hex_num(1, (unsigned long long)src->ptr + \
        (unsigned long long)(src->size - 1), 0);
    write (1, " ", 1);
    put_num_fd(1, src->size);
    put_str_fd(1, " bytes ");
    put_str_fd(1, src->start_time);
    if (src->end_time)
    {
        write (1, " ~ ", 3);
        put_str_fd(1, src->end_time);
    }
    write(1, "\n", 1);
}

void    show_size(int type)
{
    t_stack *src;
    t_stack *dest;
    size_t  ee;
    size_t  i;

    i = 0;
    ee = 0;
    if (g_all->g_stack == NULL)
        return ;
    src = g_all->g_stack;
    while (src != g_all->g_stack)
        src = g_all->g_stack;
    while (src != NULL && i < g_all->stack_size)
    {
        if (src->ptr != 0)
        {
            if (type == 0 && src->size > 0 && src->size <= TINY_SIZE)
            {
                print_show_ptr(src);
                ee++;
            }
            else if (type == 1 && src->size > TINY_SIZE && src->size <= SMALL_SIZE)
            {
                print_show_ptr(src);
                ee++;
            }
            else if (type == 2 && src->size > SMALL_SIZE)
            {
                print_show_ptr(src);
                ee++;
            }
        }
        else if (src->ptr == 0)
            break;
        if (src->next == NULL)
            break ;
        dest = src->next;
        src = dest;
        i++;
    }
    if (ee == 0)
        put_str_fd(1, "NULL\n");
}

void    show_alloc_mem_ex(void)
{
	init_lcok();
    put_str_fd(1, "-----Show Alloc Mem EX-----\n");
    put_str_fd(1, "Tiny :\n");
    show_size(0);
    put_str_fd(1, "Small :\n");
    show_size(1);
    put_str_fd(1, "Large : \n");
    show_size(2);
	pthread_mutex_unlock(&g_gardner);
}