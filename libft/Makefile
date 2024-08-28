NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = ft_strdup.c \
		ft_strlen.c \
		ft_memset.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_substr.c\
		ft_strtrim.c\
		ft_strchr.c\
		ft_itoa.c\

BONUS_OBJ = $(BONUS:.c=.o)
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all bonus

.PHONY: all clean fclean re bonus

