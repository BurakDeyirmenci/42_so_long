CC			= gcc
MINILIBX	= minilibx/libmlx.a
LFLAGS		= -framework OpenGL -framework AppKit -L./minilibx -lmlx
CFLAGS		= -I./include -I./gnl -I./libft -I./minilibx -Wall -Wextra -Werror
NAME		= so_long
SRC_DIR		= src

BSRCS		= $(wildcard $(SRC_DIR)/bonus/*_bonus.c)
BOBJS		= $(BSRCS:.c=.o)

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

testm: all
	@bash tests.sh

testb: bonus
	@bash tests.sh

run: all
	./$(NAME) maps/map2.ber

re: fclean all

clean:
	rm -rf $(OBJS)
	rm -rf $(MOBJS)
	rm -rf $(BOBJS)
	rm -rf log.txt

bonus: OBJS += $(BOBJS)
bonus: $(BOBJS) $(NAME)

fclean: clean
	rm -rf $(NAME)
	@-make clean -C minilibx

.PHONY: clean run fclean re all testm testb bonus norm