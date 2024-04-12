ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

# Define the library name
LIBNAME := libft_malloc_$(HOSTTYPE).so
SYMLINK := libft_malloc.so

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Source and object files
SRC :=  src/ft_malloc.c \
        src/ft_tst_util.c \
		src/show_util.c \

OBJ := $(SRC:.c=.o)

# Compile the project
all: $(LIBNAME)

$(LIBNAME): $(OBJ)
	$(CC) -shared -o $@ $^
	ln -sf $(LIBNAME) $(SYMLINK)

# Compile the libft library
libft:
	$(MAKE) -C libft/

# Clean objects
clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

# Full clean
fclean: clean
	rm -f $(LIBNAME) $(SYMLINK)
	$(MAKE) -C libft fclean

# Re-compile
re: fclean all