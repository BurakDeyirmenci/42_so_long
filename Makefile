CC			= gcc
MINILIBX	= minilibx/libmlx.a
LFLAGS		= -framework OpenGL -framework AppKit -L./minilibx -lmlx
CFLAGS		= -I./include -I./gnl -I./libft -I./minilibx -Wall -Wextra -Werror
NAME		= so_long
SRC_DIR		= src
SRCS		= $(wildcard $(SRC_DIR)/*.c) gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(MINILIBX):
	make -C minilibx
	@echo "MINILIBX compiling is done!"

$(NAME): $(MINILIBX) $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(NAME)

norm:
	@norminette src/*.c include/*.h gnl/*.c gnl/*.h

test: $(NAME)
	@bash tests.sh

run: $(NAME)
	./$(NAME) maps/map2.ber

re: fclean all

clean:
	rm -rf $(OBJS)
	rm -rf log.txt

bonus:
	@echo "I don't have $@:("

fclean: clean
	rm -rf $(NAME)
	@-make clean -C minilibx

.PHONY: clean run fclean re all test bonus norm