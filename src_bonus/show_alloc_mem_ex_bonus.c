/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_ex_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:01:42 by hojsong           #+#    #+#             */
/*   Updated: 2024/05/09 18:31:27 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc_bonus.h"


t_stack *new_stack_one(void *ptr, size_t idx)
{
    t_stack *result;

    result = &ptr[idx * sizeof(t_stack)];
    result->ptr = NULL;
    result->size = 0;
    result->start_time = 0;
    result->end_time = 0;
    result->next = NULL;

    return (result);
}

void    stack_add_back(t_stack *stack)
{
    t_stack *src;
    t_stack *dest;

    src = g_stack;
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

    m_ptr = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    while (m_ptr == NULL)
    {
        m_ptr = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, \
		    MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    }
    stack = new_stack_one(m_ptr, 0);
    stack->ptr = ptr;
    stack->size = size;
    stack->start_time = time(NULL);
    idx = 1;
    dest = stack;
    while((idx + 1) * sizeof(t_stack) < (size_t)getpagesize())
    {
        src = new_stack_one(m_ptr, idx);
        dest->next = src;
        dest = src;
        idx++;
    }
    if (g_stack == NULL)
        g_stack = stack;
    else
        stack_add_back(stack);
}

//malloc success
void    malloc_lst(void *ptr, size_t size)
{
    t_stack *src;
    t_stack *dest;

    src = g_stack;
    while (src && g_stack)
    {
        if(src->size == 0)
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
    char    *str;
    
    put_hex_num(1, (unsigned long long)src->ptr, 0);
    write (1, " - ", 3);
    put_hex_num(1, (unsigned long long)src->ptr + \
        (unsigned long long)(src->size - 1), 0);
    write (1, " ", 1);
    put_num_fd(1, src->size);
    if (src->start_time != 0)
    {
        str = ctime(&src->start_time);
        str[m_ft_strlen(str) - 1] = '\0';
        write (1, " ", 1);
        put_str_fd(1, str);
    }
    if (src->end_time != 0)
    {
        str = ctime(&src->end_time);
        str[m_ft_strlen(str) - 1] = '\0';
        write (1, " ~ ", 3);
        put_str_fd(1, str);
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
        if (len != 0 && src->size > size && src->size <= len && src->ptr)
        { // tiny (0, TINY_SIZE) / small (TINY_SIZE, SMALL_SIZE) 
            print_show_ptr(src);
            ee++;
        }
        else if (len == 0 && src -> size > size && src->ptr)
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
	init_lcok();
    put_str_fd(1, "Tiny :\n");
    show_size(0, TINY_SIZE);
    put_str_fd(1, "Small :\n");
    show_size(TINY_SIZE, SMALL_SIZE);
    put_str_fd(1, "Large : \n");
    show_size(SMALL_SIZE, 0);
	pthread_mutex_unlock(&g_gardner);
}