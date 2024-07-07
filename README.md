# ft_malloc
# Custom Memory Management Library

This library provides custom implementations of the memory management functions `malloc()`, `free()`, and `realloc()` using low-level system calls. Additionally, it includes a utility function `show_alloc_mem()` to display all allocated memory information.

## Features

- Custom implementation of `malloc()`, `free()`, and `realloc()`.
- Efficient memory allocation and deallocation.
- Detailed memory usage information through `show_alloc_mem()`.

## System Calls Used

- `mmap(2)`: For memory allocation.
- `munmap(2)`: For memory deallocation.
- `getpagesize(2 or 3)`: To determine the system's memory page size.
- `getrlimit(2)`: To get the resource limits, aiding in efficient memory management.

## How to Use

### malloc()

Custom implementation of the `malloc()` function to allocate memory.

```c
void *malloc(size_t size);
free()
Custom implementation of the free() function to deallocate memory.

c


void free(void *ptr);
realloc()
Custom implementation of the realloc() function to reallocate memory.

c


void *realloc(void *ptr, size_t size);
show_alloc_mem()
Displays all allocated memory information.

c


void show_alloc_mem(void);