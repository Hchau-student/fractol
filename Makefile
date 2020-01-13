NAME = fractol
CC = gcc
SRC_DIR = ./src/
OBJ_DIR = obj/
LIBFT_DIR = libft/
INC_DIRS = -I ./includes/ -I /usr/local/include
INC_LIB = -L /usr/local/lib/
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

SRCS = main.c check_name.c error.c hooks.c image.c start_programm.c \
		fracral_draw.c rotate_try.c \

OBJ = ${SRCS:c=o}

all: $(NAME)

$(addprefix $(OBJ_DIR), %.o): $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -I libft/ $(INC_DIRS) -c -o $@ $^

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	@make -C $(LIBFT_DIR)
	@$(CC) $(INC_LIB) $(addprefix $(OBJ_DIR), $(OBJ)) $(LIBFT_DIR)libft.a -I libft/ $(INC_DIRS) $(FRAMEWORK) -o $(NAME)
	@echo "\033[38;2;139;20;39m A \033[38;2;190;60;0m L \033[38;2;255;156;0m L \
	\033[38;2;252;210;0m   D \033[38;2;60;160;50m O \033[38;2;32;80;250m N \033[38;2;200;8;250m E \033[0m"

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "\033[38;2;139;20;39m A \033[38;2;190;60;0m L \033[38;2;255;156;0m L \
	\033[38;2;252;210;0m   C \033[38;2;60;160;50m L \033[36m E \033[38;2;32;80;250m A \033[38;2;200;8;250m N \033[0m"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
