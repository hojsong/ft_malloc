#include "../header/ft_malloc.h"

t_sta    *all;

int ft_strcmp(char *str1, char *str2)
{
    size_t  idx;

    if(!str1 || !str2)
        return 1;
    idx = 0;
    while(str1[idx] && str2[idx])
    {
        if(str1[idx] == str2[idx])
            idx++;
        else
            break;
    }
    if (str1[idx] || str2[idx])
        return((unsigned char)str1[idx] - (unsigned char)str2[idx]);
    return (0);
}

size_t  ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    put_str_fd(int fd, char *str)
{
    size_t i;

    i = ft_strlen(str);
    write(fd, str, i);
}

void    put_num_fd(int fd, size_t num)
{
    char s;

    if (num < 10)
        s = num + '0';
    else
    {
        put_num_fd(fd, num/10);
        s = (num % 10) + '0';
    }
    write(fd, &s, 1);
}

void    put_hex_num(int fd, unsigned long long ptr, int idx)
{
    char *str;

    str = "0123456789ABCDEF";
    if (idx == 7)
        put_str_fd(fd, "0x");
    else
        put_hex_num(fd, ptr/16, idx + 1);
    write(fd, &str[ptr % 16], 1);
}

void    put_ptr_fd(int fd, t_st *ptr)
{
    t_st    *src;
    t_st    *dest;
    size_t  idx, size;

    if (ptr == NULL)
    {
        put_str_fd(fd, "NULL!\n"); 
        return ;
    }
    src = ptr;
    put_hex_num(fd, (unsigned long long)src->ptr, 0);
    put_str_fd(fd, "\n");
    idx = 0;
    size = 1;
    while(src)
    {
        while(idx < src->max_size)
        {
            while(src->si[idx] == -1)
                idx++;
            while(src->si[idx + size - 1] == src->si[idx + size] && \
                idx + size < src->size
                )
                size++;
            if (src->si[idx] != -1)
            {
                put_hex_num(fd, (unsigned long long)src->ptr + \
                    (unsigned long long)idx, 0);
                put_str_fd(fd, " - ");
                put_hex_num(fd, (unsigned long long)src->ptr + \
                    (unsigned long long)idx + (unsigned long long)size, 0);
                put_str_fd(fd, " : ");
                put_num_fd(fd, size);
                put_str_fd(fd, " bytes\n");
            }
            if (idx + size >= src->size)
                break;
            idx += size;
            size = 1;
        }
        idx = 0;
        dest = src;
        src = dest->next;
    }
}