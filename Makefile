# **************************************************************************** #
#                                MAKEFILE                                      #
# **************************************************************************** #

NAME = so_long

# Compiler and flags
CC = cc

# CFLAGS = -Wall -Wextra -Werror
CFLAGS =

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
MLX_DIR = minilibx
LIBFT_DIR = libft

# Sources & Objects
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Includes & Library flags
INCLUDES = -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

# Default rule
all: $(NAME)

# Make libft first
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Make target executable
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

# Rule to compile .c to .o in obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create obj dir if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Cleaning rules
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
