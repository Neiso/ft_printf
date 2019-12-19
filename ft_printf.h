/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:50:07 by douatla           #+#    #+#             */
/*   Updated: 2019/12/19 17:55:03 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "srcs/libft/libft.h"

int		parse_input_string(const char *string);
int		check_char(char const *string);
int		printf_arg(void *arg, int type);
int		ft_printf(const char *string, ...);

int     character_arg(const char *string, va_list list_arg);
int     string_arg(const char *string, va_list list_arg);
int     int_decimal_arg(const char *string, va_list list_arg);
int     pointer_arg(const char *string, va_list list_arg);
int     unsigned_int_decimal_arg(const char *string, va_list list_arg);
int     unsigned_hexadecimal_arg(const char *string, va_list list_arg);

// typedef struct arg
// {
	
// }               arg;


//https://www.hackerearth.com/practice/notes/know-our-printf-variable-number-of-arguments-to-a-function/
#endif