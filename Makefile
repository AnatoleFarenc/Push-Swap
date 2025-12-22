
CC = cc
SRC_DIR = srcs
SRC = main.c parse_input.c push_swap_utils.c push_swap_utils_2.c stack_option.c a_operation.c b_operation.c\
	 a_b_operation.c movment_stack.c lis.c push_swap.c movement_stack_2.c parse_input_2.c stack_option_2.c special_cases.c
BONUS_SRC = checker_bonus.c parse_input.c push_swap_utils.c push_swap_utils_2.c stack_option.c a_operation.c b_operation.c\
	 a_b_operation.c movment_stack.c lis.c push_swap.c movement_stack_2.c parse_input_2.c stack_option_2.c special_cases.c
BONUS_SRCS = $(addprefix $(SRC_DIR)/, $(BONUS_SRC))
BONUS_OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(BONUS_SRCS))
OBJ_DIR = objs
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
CFLAGS = -Wextra -Werror -Wall -g
INCLUDES = -Iincludes -Ilibft 
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
NAME = push_swap
BONUS = checker

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BONUS): $(BONUS_OBJ) $(LIBFT)
	$(CC) $(BONUS_OBJ) $(LIBFT) -o $@

bonus: $(BONUS)

clean:
	$(RM) -r $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all
