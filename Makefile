# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: douatla <douatla@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 13:16:24 by douatla           #+#    #+#              #
#    Updated: 2020/03/03 09:01:58 by douatla          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GFLAG = gcc -Wall -Werror -Wextra

LIBFT = libft

FILES = srcs/func_utiles.c srcs/func_utiles_2.c srcs/find_tokken.c srcs/deal_tokken.c srcs/check_flag.c srcs/type_of_flag.c srcs/type_of_flag2.c srcs/ft_printf.c 

FILES_O = ${FILES:.c=.o}

HEADER = ft_printf.h

EXEC = ft_printf

NAME = libftprintf.a

DEL = rm -Rf


%.o: %.c
		gcc -Wall -Werror -Wextra -c -o $@ $<


all : ${LIBFT} ${NAME}

${NAME}: ${FILES_O}
	ar -rc libftprintf.a ${FILES_O}

${LIBFT}:
	@${MAKE} -C ./libft
	cp ./libft/libft.a .
	mv libft.a libftprintf.a

clean :
	${DEL} ${FILES_O}
	${MAKE} clean -C ./libft

fclean : clean
	${DEL} ${NAME}
	${MAKE} fclean -C ./libft

re : fclean all

exec: ${LIBFT}
	@gcc ${FILES} -Llib -lft -o ${EXEC}
	@./ft_printf | cat -e

.PHONY : ${LIBFT} ${NAME} all clean re fclean exec
