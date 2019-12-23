GCC = gcc -Wall -Werror -Wextra

LIBFT = libft.a

FILES = utils.c check_flag.c  type_of_flag.c type_of_flag2.c ft_printf.c main.c

HEADER = ft_printf.h

NAME = ft_printf

all: ${NAME}
	echo 'done'
${NAME}:
	gcc -o ${NAME} ${HEADER} ${LIBFT} ${FILES}

ubuntu :
	gcc -o ${NAME} ${HEADER} libft.so ${FILES} ./srcs/libft/*.o

re: all


