/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:50:07 by douatla           #+#    #+#             */
/*   Updated: 2019/12/23 16:50:06 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "srcs/libft/libft.h"

/*
**      ===================
**     |    ft_printf.c    |
**      ===================
*/

int		ft_printf(const char *string, ...);

/*
**-------------------------------------------------------------------
*/

/*
**      ===================
**     |    check_flag.c   |
**      ===================
*/

int     	deal_with_arg(const char *string, va_list list_arg);
char	    *ft_strjoin_pourcent(char *buffer);
char	    *find_next_arg(char *string);
int 		type_of_arg(const char *str);

/*
**-------------------------------------------------------------------
*/

/*
**      ======================
**     |    type_of_flag.c    |
**      ======================
*/

int     character_arg(const char* string, va_list list_arg);
int     string_arg(const char* string, va_list list_arg);
int     int_decimal_arg(const char* string, va_list list_arg);
int     unsigned_int_decimal_arg(const char* string, va_list list_arg);
int     unsigned_hexadecimal_arg(const char* string, va_list list_arg);

/*
**-------------------------------------------------------------------
*/

/*
**      =======================
**     |    type_of_flag2.c    |
**      =======================
*/

/*
**-------------------------------------------------------------------
*/

int     pointer_arg(const char* string, va_list list_arg);

/*
**      ===============
**     |    utils.c    |
**      ===============
*/

char    *ft_itoa_unsigned(unsigned int n);
char	*ft_itoa_base16(unsigned int n);

/*
**-------------------------------------------------------------------
*/

//https://www.hackerearth.com/practice/notes/know-our-printf-variable-number-of-arguments-to-a-function/
#endif