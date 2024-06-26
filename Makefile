CC			= gcc
MINILIBX	= minilibx/libmlx.a
LFLAGS		= -framework OpenGL -framework AppKit -L./minilibx -lmlx
CFLAGS		= -I./include -I./gnl -I./libft -I./minilibx -Wall -Wextra -Werror
NAME		= so_long
SRC_DIR		= src


MSRCS		= $(wildcard $(SRC_DIR)/mandatory/*.c)
MOBJS		= $(MSRCS:.c=.o)

SRCS		= $(wildcard $(SRC_DIR)/*.c) gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)

all: OBJS += $(MOBJS)
all: $(MOBJS) $(NAME) 

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(MINILIBX):
	make -C minilibx 2> /dev/null
	@echo "MINILIBX compiling is done!"

$(NAME): $(MINILIBX) $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(NAME)

norm:
	@norminette src/*.c include/*.h gnl/*.c gnl/*.h

test: all
	@bash tests.sh

run: all
	./$(NAME) maps/map1.ber

re: fclean all

push:
	make fclean
	git add gnl/* include/* maps/* sprite/* src/* Makefile
	git commit -m "$(c)"
	git push -u git@vogsphere.42istanbul.com.tr:vogsphere/intra-uuid-0d1a5090-92ba-47c6-b5d7-8d928e2ecbac-4049984-rdeyirme

clean:
	rm -rf $(OBJS)
	rm -rf $(MOBJS)
	rm -rf log.txt


fclean: clean
	rm -rf $(NAME)
	@-make clean -C minilibx

.PHONY: clean run fclean re all test norm