GCC = gcc -Wall -Werror -Wextra

LIBFT = libft

FILES = srcs/func_utiles.c srcs/func_utiles_2.c srcs/find_tokken.c srcs/deal_tokken.c srcs/check_flag.c srcs/type_of_flag.c srcs/type_of_flag2.c srcs/ft_printf.c 

FILES_O = ${FILES:.c=.o}

HEADER = ft_printf.h

EXEC = ft_printf

NAME = libftprintf.a

DEL = rm -Rf

all : ${LIBFT} ${NAME}

${NAME}: ${FILES_O}
	ar -rc libftprintf.a ./library/libft.a ${FILES_O}

${LIBFT}:
	@${MAKE} -C ./libft
	@mv ./libft/libft.a ./library


clean :
	${DEL} ${FILES_O}
	${DEL} ./library/libft.a

fclean : clean
	${DEL} ${NAME}

re : fclean all

exec: ${LIBFT}
	@gcc ${FILES} -Llib -lft -o ${EXEC}
	@./ft_printf | cat -e

.PHONY : ${LIBFT} ${NAME}
