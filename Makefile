NAME = libftprintf.a

SRCS = ft_printf.c\
	ft_nbr_count_hex.c\
	ft_nbr_count_p.c\
	ft_print_dec_num.c\
	ft_print_pointer.c\
	ft_print_unsigned_lx.c\
	ft_print_unsigned_u.c\
	ft_print_unsigned_x.c\
	ft_printf_main_function.c\
	ft_printf_utils.c\
	ft_put_n_char.c\
	ft_putchar_fd.c\
	ft_putnbr_fd.c\
	ft_putnbr_hex_p.c\
	ft_putnbr_hex.c\
	ft_strlen.c\

REG_OBJS = $(SRCS:%.c=%.o)

BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

CC = gcc

CFLAGS = -Wextra -Werror -Wall

RM = rm -f


.c.o:
	$(CC) $(CFLAGS) -c $< -I ft_printf.h


all:	$(NAME)

bonus:	$(BONUS_OBJS) $(REG_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS) $(REG_OBJS)

$(NAME):	$(REG_OBJS)
			 ar rc $(NAME) $(REG_OBJS)

clean: 
	$(RM) $(REG_OBJS) $(BONUS_OBJS)
fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all	clean fclean re bonus