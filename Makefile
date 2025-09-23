
NAME := push_swap

SRC_DIR := push_swap_file/src
SRC := parse.c \
	push_swap.c \
	moves.c \
	sort.c \
	stack_utils.c \
	utils.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_DIR := obj
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))

CC := cc
CFLAGS := -Wall -Werror -Wextra
LIBFT_DIR := ./lib/libft
LIBFT := $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT): $(LIBFT_DIR)
	make -C$(LIBFT_DIR);

$(LIBFT_DIR):
	git clone https://github.com/YukiHalf/42_libft.git $@;

$(OBJ_DIR):
	mkdir obj

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -L$(LIBFT_DIR) -lft -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c push_swap_file/inc/push_swap.h | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -Ipush_swap_file/inc $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C$(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rmdir $(OBJ_DIR)
	rm -rf $(LIBFT_DIR)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all, clean, fclean, re
