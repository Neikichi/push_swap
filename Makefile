NAME = push_swap
BONUS_NAME = checker

BONUS_DIR = bonus
INC_DIR = include
LIBFT_DIR = libft
SRC_DIR = src

SRC = \
	  $(SRC_DIR)/main.c \
	  $(SRC_DIR)/op_utils.c \
	  $(SRC_DIR)/op_utils2.c \
	  $(SRC_DIR)/print_utils.c \
	  $(SRC_DIR)/ps_is.c \
	  $(SRC_DIR)/ps_pivot.c \
	  $(SRC_DIR)/ps_qs.c \
	  $(SRC_DIR)/ps_qs2.c \
	  $(SRC_DIR)/push_swap.c \
	  $(SRC_DIR)/push_swap1.c \
	  $(SRC_DIR)/push_swap2.c \
	  $(SRC_DIR)/stacks_utils.c \
	  $(SRC_DIR)/stacks_utils2.c \
	  $(SRC_DIR)/stacks_utils3.c \
	  $(SRC_DIR)/swap_utils.c \
	  $(SRC_DIR)/swap_utils2.c \
	  $(SRC_DIR)/swap_utils3.c \

# SRC = $(wildcard $(SRC_DIR)/*.c)

PSRC = $(filter-out $(SRC_DIR)/main.c, $(SRC))
POBJ = $(PSRC:%.c=%.o)

BSRC = $(BONUS_DIR)/checker_bonus.c \
	   $(BONUS_DIR)/swap_op_bonus.c \
	   $(BONUS_DIR)/swap_op2_bonus.c \

BOBJ = $(BSRC:%.c=%.o)

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
	@echo "Creating $(NAME)..."
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 
	@echo "Created $(NAME)"

$(LIBFT):
	@make -C $(LIBFT_DIR) all

bonus: IFLAGS += -I$(BONUS_DIR)
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BOBJ) $(POBJ) $(LIBFT)
	@echo "Creating bonus $(BONUS_NAME)..."
	@$(CC) $(CFLAGS) $(IFLAGS) $(POBJ) $(BOBJ) $(LIBFT) -o $(BONUS_NAME) 
	@echo "Created $(BONUS_NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@echo "Removing objects files..."
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJ) $(BOBJ)
	@echo "Objects files removed."

fclean: clean
	@echo "Removing $(NAME)..."
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "$(NAME) removed."

re: fclean all

debug: CFLAGS += -g -fpic
debug: clean all
	@echo "Enable debug mode"

.PHONY: all clean fclean re bonus debug
