CC = cc      # dont forget to add the compiler flags
CFLAGS = -Wall -Wextra -Werror
MLXFLAG = -lXext -lX11

ARC = mlx_linux/minilibx-linux/libmlx_Linux.a
HED1 = mlx_linux/minilibx-linux/
HED2 = mandatory/include/
HED3 = mandatory/src/ft_printf/
HED4 = mandatory/src/get_next_line/

HEDB2 = bonus/include/
HEDB3 = bonus/src/ft_printf/
HEDB4 = bonus/src/get_next_line/

NAME = so_long
NAME_BONUS = so_long_bonus

SRC = $(shell find mandatory/src -name "*.c")
SRC_BONUS = $(shell find bonus/src -name "*.c")

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(ARC) -I$(HED1) -I$(HED2) -I$(HED3) -I$(HED4) -lXext -lX11 -lm -o $(NAME)

$(NAME_BONUS): $(SRC_BONUS)
	$(CC) $(CFLAGS) $(SRC_BONUS) $(ARC) -I$(HED1) -I$(HEDB2) -I$(HEDB3) -I$(HEDB4) -lXext -lX11 -lm -o $(NAME_BONUS)

fclean:
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all fclean re
