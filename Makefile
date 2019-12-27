GCC = gcc -Wall -Werror -Wextra

LIBFT = libft.a

FILES = utils.c find_tokken.c deal_tokken.c check_flag.c  type_of_flag.c type_of_flag2.c ft_printf.c main.c

HEADER = ft_printf.h

EXEC = ft_printf

NAME = libftprintf.a

DEL = rm -Rf

all : ${NAME}

${NAME}:
	${GCC} -L -o ${FILES}
	ar rc ${NAME} ${FILES_O}

clean :
	${DEL} *.o

fclean : clean
	${DEL} ${NAME}

re : fclean all
