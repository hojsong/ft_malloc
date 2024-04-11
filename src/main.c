#include "../header/ft_malloc.h"

t_sta    *all;

int main(){
    char *str, *str2, *str3;

    str = malloc(10000);
    str2 = malloc(1000);
    str3 = malloc(200);
    show_alloc_mem();
    printf("----------------------------------------\n");
    str = realloc(str, 100);
    show_alloc_mem();
    printf("----------------------------------------\n");
    free(str3); // 200
    free(str2); // 1000
    free(str); // 100
    show_alloc_mem();
}