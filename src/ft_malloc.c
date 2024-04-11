#include "../header/ft_malloc.h"

t_sta    *all;

void    *malloc(size_t size)
{
    t_st    *dest;
    t_st    *m;
    t_st    *result;
    size_t  i;
    size_t  len;
    int     x;

    result = NULL;
    if (all == NULL)
        all = mmap(0, sizeof(t_sta), PROT_READ | PROT_WRITE, \
            MAP_PRIVATE | MAP_ANONYMOUS, 0, 0 );
    if (size <= 1024)
    {
        m = all->tiny;
        if (m == NULL)
        {
            all->tiny = newlst(size);
            return (all->tiny->ptr);
        }
    }
    else if (size <= 4096)
    {
        m = all->small;
        if (m == NULL)
        {
            all->small = newlst(size);
            return (all->small->ptr);
        }
    }
    else
    {
        result = large(size);
        return result->ptr;
    }
    while(m)
    {
        if (m == NULL)
        {
            result = newlst(size);
            m->next = result;
            return (result->ptr);
        }
        else if (m->size + size <= m->max_size)
        {
            result = m;
            i = 0;
            len = m->size;
            x = m->si[m->size - 1] + 1;
            while (i < size)
            {
                result->si[i + result->size] = x;
                i++;
            }
            m->size += size;
            break;
        }
        dest = m->next;
        m = dest;
    }
    return (&m->ptr[len]);
}

void    free(void *ptr)
{
    t_st    *dest;
    t_st    *src;

    dest = NULL;
    src = all->tiny;
    while (src)
    {
        if (ptr == src->ptr || (ptr >= src->ptr && ptr < src->ptr + src->max_size))
            {
                ft_replace(ptr, src, dest, "tiny"); 
                return ;
            }
        dest = src;
        src = dest->next;
    }
    dest = NULL;
    src = all->small;
    while (src)
    {
        if (ptr == src->ptr || (ptr >= src->ptr && ptr < src->ptr + src->max_size))
            {
                ft_replace(ptr, src, dest, "small");
                return ;
            }
        dest = src;
        src = dest->next;
    }
    dest = NULL;
    src = all->large;
    while (src)
    {
        if (ptr == src->ptr || (ptr >= src->ptr && ptr < src->ptr + src->max_size))
            {
                ft_replace(ptr, src, dest, "large");
                return ;
            }
        dest = src;
        src = dest->next;
    }
}

void    *realloc(void *ptr, size_t size)
{
    ft_free(ptr);
    ptr = ft_malloc(size);
    return ptr;
}

void    show_alloc_mem()
{
    put_str_fd(1, "TINY : ");
    put_ptr_fd(1, all->tiny);
    put_str_fd(1, "SMALL : ");
    put_ptr_fd(1, all->small);
    put_str_fd(1, "LARGE : ");
    put_ptr_fd(1, all->large);
}
