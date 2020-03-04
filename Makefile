# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: douatla <douatla@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 13:16:24 by douatla           #+#    #+#              #
#    Updated: 2020/03/04 14:50:54 by douatla          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GFLAG = gcc -Wall -Werror -Wextra

LIBFT = ../libft.a

FILES = srcs/func_utiles.c srcs/func_utiles_2.c srcs/find_tokken.c srcs/deal_tokken.c srcs/check_flag.c srcs/type_of_flag.c srcs/type_of_flag2.c srcs/ft_printf.c 

FILES_O = ${FILES:.c=.o}

HEADER = ./srcs/ft_printf.h

EXEC = ft_printf

NAME = libftprintf.a

DEL = rm -Rf

YELLOW = \033[0;33m

NO_COLOR = \033[0m

all : ${NAME}

%.o: %.c ${HEADER}
	@${GFLAG} -c -o $@ $<	

${NAME}: ${FILES_O}
	@ar -rcs ${LIBFT} ${FILES_O}
	@python3 -c 'print("${YELLOW}Ft_printf compiled with success.${NO_COLOR}\n")'

clean :
	@${DEL} ${FILES_O}

re : all

.PHONY : ${NAME} all clean re fclean exec
