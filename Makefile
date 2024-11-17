SRCS	=	ft_putaddr.c ft_putnbr.c ft_putnbr_unsigned.c\
		ft_printf.c ft_putchar.c ft_putnbr_base.c\
		ft_putstr.c
NAME	= libftprintf.a
OBJS = ${SRCS:.c=.o}
AR = ar rc
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re