NAME = so_long

SRCS =	main.c \
		helper/parse.c \
		helper/tools.c \
		helper/checks.c \
		helper/checkmap.c \
		helper/moves.c \
		helper/maptools.c \
		helper/printelem.c \
		mlxfunc/hooks.c \
		mlxfunc/draw.c \

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

INCL= ./libft/libft.a \

CC = gcc

%.o: %.c
	@make libs
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -Iincludes $(INCL) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

libs:
	@make bonus -C ./libft/
	@make -C ./mlx/

clean:
	@rm -rf $(OBJS)
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

lclean:
	@make fclean -C ./libft/
	@make clean -C ./mlx/

re: fclean all