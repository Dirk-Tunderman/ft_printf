NAME = libftprintf.a

SOURCES =	ft_printf.c \
			ft_print_x.c \
			ft_print_p.c \
			ft_unsigned_toa.c \
			ft_put.c \
			ft_print_xx.c \
			ft_itoa_u.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ./libft
	cp libft/libft.a $(NAME)
	gcc -c -Wall -Werror -Wextra $(SOURCES)
	ar -rcs $(NAME) $(OBJECTS)
 
clean:
	make clean -C ./libft
	rm -rf $(OBJECTS)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re:	fclean all
