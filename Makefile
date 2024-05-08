NAME = libft_malloc_$(HOSTTYPE).so
NAME_BO = libft_malloc_$(HOSTTYPE)_bonus.so
LINK_NAME = libft_malloc.so
LIBFT_DIR = ./libft

# SRC_DIR = ./src
# SRC_FILES = ft_malloc.c \
# 			ft_tst_util.c \
# 			ft_tst_util2.c \
# 			ft_tst_util3.c \
# 			ft_tst_util4.c \
# 			show_util.c \

# SRC_DIR = ./src2
# SRC_FILES = malloc.c \
# 			free.c \
# 			show_alloc_mem.c \
# 			realloc.c \
# 			util.c \

SRC_DIR = 	./src3
SRC_FILES = malloc.c \
			free.c \
			show_alloc_mem.c \
			realloc.c \
			util.c \

SRC_BONUS_DIR = 	./src_bonus
SRC_BONUS_FILES =	malloc_bonus.c \
					free_bonus.c \
					show_alloc_mem_bonus.c \
					realloc_bonus.c \
					util_bonus.c \
					show_alloc_mem_ex_bonus.c \

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
SRC_BO = $(addprefix $(SRC_BONUS_DIR)/,$(SRC_BONUS_FILES))
LIBFT_SRC = $(addprefix $(LIBFT_DIR)/,$(LIBFT_FILES))
OBJ = $(SRC:.c=.o) $(LIBFT_SRC:.c=.o)
OBJ_BO = $(SRC_BO:.c=.o) $(LIBFT_SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

# HOSTTYPE 환경 변수 확인 및 설정
ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

ifdef BONUS
	OBJ_CUR = $(OBJ_BO)
	NAME_CUR = $(NAME_BO)
else
	OBJ_CUR = $(OBJ)
	NAME_CUR = $(NAME)
endif

.DEFAULT_GOAL : all

all: $(NAME_CUR)
	chmod 777 $(NAME_CUR)
	$(CC) $(CFLAGS) -o a.out main.c -L. -lft_malloc

$(NAME_CUR): $(OBJ_CUR)
	$(CC) $(CFLAGS) -shared -o $(NAME_CUR) $(OBJ_CUR)
	rm -rf $(LINK_NAME)
	ln -s $(NAME_CUR) $(LINK_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BO)

fclean: clean
	rm -rf $(NAME) $(NAME_BO)
	rm -rf $(LINK_NAME)
	rm -rf a.out*

re: fclean all

bonus :
	make BONUS=1 $(NAME_BO)
	chmod 777 $(NAME_BO)
	$(CC) $(CFLAGS) -o a.out main_bonus.c -L. -lft_malloc

.PHONY: all clean fclean re bonus