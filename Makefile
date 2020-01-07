GCC = gcc -Wall -Werror -Wextra

LIBFT = libft.a

FILES = func_utiles.c handeling_errors.c find_tokken.c deal_tokken.c check_flag.c  type_of_flag.c type_of_flag2.c ft_printf.c main.c

FILES_O = ${FILES:.c=.o}

HEADER = ft_printf.h

EXEC = ft_printf

NAME = libftprintf.a

DEL = rm -Rf

all : ${NAME}

${NAME}: ${FILES_O}
	ar -rc libftprintf.a ${FILES_O} srcs/libft/*.o

exec:
	@gcc ${FILES} -Llib -lft -o ${EXEC}
	@./ft_printf | cat -e

clean :
	${DEL} *.o

fclean : clean
	${DEL} ${NAME}

re : fclean all
