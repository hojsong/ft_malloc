#include "libft/libft.h" // libft 라이브러리의 헤더 파일 포함
#include "header/malloc.h"

int main(void) {
    char *str;

    // libft_malloc.so를 사용하여 메모리 할당
    str = ft_strdup("Hellow~~~~\n");
    ft_putstr_fd(str, 1); // libft의 ft_putstr 함수를 사용하여 문자열 출력
    show_alloc_mem();
    free(str); // 할당된 메모리 해제
    show_alloc_mem();

    return (0);
}