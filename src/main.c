#include "../header/ft_malloc.h"

t_sta    *all;

int main(){
    char *str, *str2, *str3;

    str = ft_malloc(10000);
    str2 = ft_malloc(1000);
    str3 = ft_malloc(200);
    show_alloc_mem();
    printf("----------------------------------------\n");
    str = ft_realloc(str, 100);
    show_alloc_mem();
    printf("----------------------------------------\n");
    ft_free(str3); // 200
    ft_free(str2); // 1000
    ft_free(str); // 100
    show_alloc_mem();
}