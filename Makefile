NAME = libft_malloc_$(HOSTTYPE).so
LINK_NAME = libft_malloc.so
LIBFT_DIR = ./libft

# SRC_DIR = ./src
# SRC_FILES = ft_malloc.c \
# 			ft_tst_util.c \
# 			ft_tst_util2.c \
# 			ft_tst_util3.c \
# 			ft_tst_util4.c \
# 			show_util.c \

SRC_DIR = ./src2
SRC_FILES = malloc.c \
			free.c \
			show_alloc_mem.c \
			realloc.c \
			util.c \

LIBFT_FILES = ft_isalpha.c \
			ft_toupper.c \
			ft_isdigit.c \
			ft_tolower.c \
			ft_isalnum.c\
			ft_strchr.c \
			ft_isascii.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c\
			ft_strnstr.c \
			ft_atoi.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c\
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_calloc.c \
			ft_strdup.c\
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c\
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \

SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
LIBFT_SRC = $(addprefix $(LIBFT_DIR)/,$(LIBFT_FILES))
OBJ = $(SRC:.c=.o) $(LIBFT_SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=undefined -g3

# HOSTTYPE 환경 변수 확인 및 설정
ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

.DEFAULT_GOAL : all

all: $(NAME)
	chmod 777 $(NAME)
	$(CC) $(CFLAGS) -o a.out main.c -L. -lft_malloc

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -shared -o $(NAME) $(OBJ)
	ln -s $(NAME) $(LINK_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LINK_NAME)

re: fclean all

.PHONY: all clean fclean re