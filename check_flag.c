/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:26:45 by douatla           #+#    #+#             */
/*   Updated: 2019/12/19 17:51:59 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		character_arg(const char *string, va_list list_arg)
{
	return (0);
}
int		string_arg(const char *string, va_list list_arg)
{
	return (0);
}
int		int_decimal_arg(const char *string, va_list list_arg)
{
	int value;
	char *value_string;

	value = va_arg(list_arg, int);
	value_string = ft_itoa(value);
	write(1, value_string, ft_strlen(value_string));
	return (1);
}
int		pointer_arg(const char *string, va_list list_arg)
{
	return (0);
}
int		unsigned_int_decimal_arg(const char *string, va_list list_arg)
{
	return (0);
}
int		unsigned_hexadecimal_arg(const char *string, va_list list_arg)
{
	return (0);
}
