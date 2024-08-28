NAME= so_long
SRCS= main.c \
	  check_map.c\
	  check_map2.c\
	  check_map3.c\
	  control.c\
	  read_map.c\
	  utils_1.c\
	  utils.c\
	  mlx_game.c\
	  mlx_game2.c\
	  mlx_game3.c\
	  gnl/get_next_line.c\
	  gnl/get_next_line_utils.c\

OBJS=$(SRCS:.c=.o)

CC=gcc
CFLAGS= -Wall -Wextra -Werror -g
RM= rm -rf
PRINTF=./ft_printf/libftprintf.a 
LIBFT= ./libft/libft.a 
MLX=./mlx/libmlx.a
LDFLAGS = -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(OBJS)
	make -C ./ft_printf -s
	make -C ./libft -s
	make -C ./mlx 2>/dev/null
	$(CC) $(CFLAGS) $(OBJS)  $(PRINTF) $(LIBFT)  $(MLX)  $(LDFLAGS) -o $(NAME)

clean: 
	make clean -C ./ft_printf -s
	make clean -C ./libft -s
	$(RM) $(OBJS)


fclean: clean
	make fclean -C ./ft_printf -s
	make fclean -C ./libft -s
	make clean -C ./mlx -s
	$(RM) $(NAME)

re: fclean all

.PHONY:all clean fclean re