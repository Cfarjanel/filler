NAME = resources/players/cfarjane.filler

SRCS = srcs/filler.c srcs/parsing.c srcs/algo.c srcs/place.c

FLAGS = -Wall -Werror -Wextra -I./includes -ggdb

OBJ = $(SRCS:.c=.o)

CL=\x1b[35m
GREEN=\033[1;32m
RED=\033[1;31m
CL2=\x1b[36m
NC=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@echo "$(GREEN)✓$(NC)$(CL) Objects of libft compiled$(NC)"
	@gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a
	@echo "$(GREEN)✓$(NC)$(CL) Executable $(NAME) built$(NC)"

%.o: %.c
	@$(CC) -c $(FLAGS) $< -o $@

clean:
	@make clean -C libft
	@echo "$(RED)x$(NC)$(CL2) Objects of libft cleaned$(NC)"
	@rm -f $(OBJ)
	@echo "$(RED)x$(NC)$(CL2) Objects of $(NAME) cleaned$(NC)"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "$(RED)x$(NC)$(CL2) Executable $(NAME) cleaned$(NC)"

re: fclean all
