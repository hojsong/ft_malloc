/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_ex_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:01:42 by hojsong           #+#    #+#             */
/*   Updated: 2024/05/08 12:11:05 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc_bonus.h"

t_sta			*g_all;
t_stack         *g_stack;
pthread_mutex_t	*g_gardner;

void    new_stack(void *ptr, size_t size)
{
    t_stack *stack;
    t_stack *src;
    t_stack *dest;
    t_stack *x;
    size_t  idx;
    void    *em_p;

    em_p = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    stack = &em_p[0];
    stack->ptr = ptr;
    stack->size = size;
    stack->start_time = time(NULL);
    stack->end_time = 0;
    dest = stack;
    x = stack;
    idx = 1;
    while ((idx + 1) * sizeof(t_stack) < (size_t)getpagesize())
    {
        dest = &em_p[sizeof(t_stack) * idx];
        dest->ptr = NULL;
        dest->size = 0;
        dest->start_time = 0;
        dest->end_time = 0;
        x->next = dest;
        x = dest;
        src = dest->next;
        dest = src;
        idx++;
    }
    dest->next = NULL;
    if (g_stack == NULL)
        g_stack = stack;
    else
    {
        dest = g_stack;
        while (dest->next)
        {
            src = dest->next;
            dest = src;
        }
        dest->next = stack;
    }
}

//malloc success
void    malloc_lst(void *ptr, size_t size)
{
    t_stack *src;
    t_stack *dest;

    src = g_stack;
    while (src && g_stack)
    {
        if(src->ptr == NULL)
        {
            src->ptr = ptr;
            src->size = size;
            src->start_time = time(NULL);
            return ;
        }
        if (src->next == NULL)
            break;
        dest = src->next;
        src = dest;        
    }
    new_stack(ptr, size);
}

// free success
void    free_lst(void   *ptr)
{
    t_stack *src;
    t_stack *dest;
    
    src = g_stack;
    while (src)
    {
        if(src->ptr == ptr && src->end_time == 0)
        {
            src->end_time = time(NULL);
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
    if (src->start_time)
    {
        write (1, " ", 1);
        put_num_fd(1, src->start_time);
    }
    if (src->end_time)
    {
        write (1, " ", 1);
        put_num_fd(1, src->end_time);   
    }
    write(1, "\n", 1);
}

void    show_size(size_t size, size_t len)
{
    t_stack *src;
    t_stack *dest;
    size_t  ee;

    ee = 0;
    src = g_stack;
    while (src)
    {
        if (len != 0 && src->size > size && src->size <= len)
        { // tiny (0, TINY_SIZE) / small (TINY_SIZE, SMALL_SIZE) 
            print_show_ptr(src);
            ee++;
        }
        else if (len == 0 && src -> size > size)
        { // large (SAMLL_SIZE, 0)
            print_show_ptr(src);
            ee++;
        }
        dest = src->next;
        src = dest;        
    }
    if (ee == 0)
        put_str_fd(1, "NULL\n");
}

void    show_alloc_mem_ex(void)
{
    put_str_fd(1, "Tiny :\n");
    show_size(0, TINY_SIZE);
    put_str_fd(1, "Small :\n");
    show_size(TINY_SIZE, SMALL_SIZE);
    put_str_fd(1, "Large : \n");
    show_size(SMALL_SIZE, 0);
}