CC = cc
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
    ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c    ft_strlen.c\
    ft_bzero.c ft_calloc.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
    ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_putnbr_fd.c\
    ft_strncmp.c ft_strnstr.c ft_strdup.c ft_toupper.c ft_tolower.c\
    ft_memset.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c\
    ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
    ft_print_char.c ft_print_dec.c ft_print_hex.c ft_printf.c ft_print_string.c\
    ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c\
    ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c\
    get_next_line_utils.c get_next_line.c
BONUS_OBJ = ${BONUS:.c=.o}
FLAGS = -Wall -Wextra -Werror
OBJ = ${SRC:.c=.o}
NAME = libft.a
RM = rm -rf

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJ} ${BONUS_OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all