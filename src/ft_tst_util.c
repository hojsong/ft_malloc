#include "../header/ft_malloc.h"

t_sta    *all;

void    ft_replace(void *ptr, t_st *src, t_st *dest, char *str)
{
    size_t idx;
    size_t size;

    idx = ptr - src->ptr;
    size = 1;
    while(src->si[idx + size] == src->si[idx])
    {
        src->si[idx + size] = -1;
        size++;
    }
    src->si[idx] = -1;
    idx = 0;
    while(idx < src->max_size)
    {
        if (src->si[idx] == -1)
            idx++;
        else
            break;
    }
    if (idx == src->max_size)
    {
        if (!dest && src->next)
        {
            if(!ft_strcmp(str,"tiny"))
                all->tiny = src->next;
            else if(!ft_strcmp(str,"small"))
                all->small = src->next;
            else if(!ft_strcmp(str,"large"))
                all->large = src->next;
        }
        else if (!dest && !src->next)
        {
            if(!ft_strcmp(str,"tiny"))
                all->tiny = NULL;
            else if(!ft_strcmp(str,"small"))
                all->small = NULL;
            else if(!ft_strcmp(str,"large"))
                all->large = NULL;
        }
        else
        {
            dest->next = src->next;
            munmap(ptr, src->max_size);
            munmap(src->si, sizeof(int) * src->max_size);
            munmap(src, sizeof(t_st));
            src = NULL;
        }
    }
}

t_st    *newlst(size_t size)
{
    t_st    *result;
    size_t  i;

    i = 0;
    result = mmap(0, sizeof(t_st), PROT_READ | PROT_WRITE, \
            MAP_PRIVATE | MAP_ANONYMOUS, 0, 0 );
    if (result == MAP_FAILED)
    {
        put_str_fd(2, "");
        return (NULL);
    }
    result->ptr = mmap(0, size, PROT_READ | PROT_WRITE, \
            MAP_PRIVATE | MAP_ANONYMOUS, 0, 0 );
    if (result == MAP_FAILED)
    {
        free(result);
        put_str_fd(2, "Mmap Error\n");
        return (NULL);
    }
    result->max_size = ((size / 8192) + 1) * 8192;
    result->size = size;
    result->si = mmap(0, sizeof(int) * result->max_size, PROT_READ | PROT_WRITE, \
            MAP_PRIVATE | MAP_ANONYMOUS, 0, 0 );
    if (result->si == MAP_FAILED)
    {
        free(result);
        put_str_fd(2, "Mmap Error\n");
        return (NULL);
    }
    while (i < result->max_size)
    {
        if (i < size)
            result->si[i] = 0;
        else
            result->si[i] = -1;
        i++;
    }
    result->next = NULL;
    return (result);
}

t_st    *large(size_t size)
{
    t_st    *src;
    t_st    *dest;

    src = all->large;
    if (src)
    {
        while(src->next)
        {
            dest = src;
            src = dest->next;
        }
        src->next = newlst(size);
    }
    else
    {
        src = newlst(size);
        all->large = src;
    }
    return src;
}