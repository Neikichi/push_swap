NAME = push_swap

INC_DIR = include
LIBFT_DIR = libft
SRC_DIR = src

# SRC = $(wildcard $(CHAR_DIR)/*.c) \
#       $(wildcard $(STRING_DIR)/*.c) \
#       $(wildcard $(MEMORY_DIR)/*.c) \
#       $(wildcard $(LIST_DIR)/*.c) \
#       $(wildcard $(NUMBER_DIR)/*.c) \
#       $(wildcard $(PRINTF_DIR)/*.c) \
#       $(wildcard $(IO_DIR)/*.c)
#
SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(SRC:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR)
LFLAGS = -l$(LIBFT_DIR)/libft.a
LIBFT = $(LIBFT_DIR)/libft.a
AR = ar
ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "Creating library..."
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 
	@echo "Created $(NAME)"

$(LIBFT):
	@make -C $(LIBFT_DIR) all

bonus: all

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@echo "Removing objects files..."
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	@echo "Objects files removed."

fclean: clean
	@echo "Removing $(NAME)..."
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(NAME) removed."

re: fclean all

debug: CFLAGS += -g -fpic
debug: fclean all
	@echo "Enable debug mode"

.PHONY: all clean fclean re bonus debug
