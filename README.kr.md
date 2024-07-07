ft_malloc
사용자 정의 메모리 관리 라이브러리
이 라이브러리는 저수준 시스템 호출을 사용하여 메모리 관리 함수 malloc(), free(), realloc()의 사용자 정의 구현을 제공합니다. 또한 할당된 모든 메모리 정보를 표시하는 유틸리티 함수 show_alloc_mem()도 포함되어 있습니다.
기능

malloc(), free(), realloc()의 사용자 정의 구현
효율적인 메모리 할당 및 해제
show_alloc_mem()을 통한 상세한 메모리 사용 정보

사용된 시스템 호출

mmap(2): 메모리 할당용
munmap(2): 메모리 해제용
getpagesize(2 또는 3): 시스템의 메모리 페이지 크기 결정
getrlimit(2): 효율적인 메모리 관리를 위한 리소스 제한 확인

사용 방법
malloc()
메모리를 할당하는 malloc() 함수의 사용자 정의 구현입니다.
void *malloc(size_t size);
free()
메모리를 해제하는 free() 함수의 사용자 정의 구현입니다.
void free(void *ptr);
realloc()
메모리를 재할당하는 realloc() 함수의 사용자 정의 구현입니다.
void *realloc(void *ptr, size_t size);
show_alloc_mem()
할당된 모든 메모리 정보를 표시합니다.
void show_alloc_mem(void);