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

LIBFT= ./libft/libft.a

MLX= ./mlx/libmlx.a

CC = gcc

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(INCL) $(MLX)
	$(CC) $(FLAGS) $(SRCS) -Iincludes $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	@make bonus -C ./libft/
	
$(MLX):
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
