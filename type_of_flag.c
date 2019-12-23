/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:26:45 by douatla           #+#    #+#             */
/*   Updated: 2019/12/23 16:56:53 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		character_arg(const char* string, va_list list_arg)
{
	char value;

	(void) string;
	value = va_arg(list_arg, int);
	write(1, &value, 1);
	return (0);
}
int		string_arg(const char* string, va_list list_arg)
{
	char *value;

	(void) string;
	value = va_arg(list_arg, char*);
	write(1, value, ft_strlen(value));
	return (1);
}
int		int_decimal_arg(const char *string, va_list list_arg)
{
	int value;
	char *value_string;

	(void) string;
	value = va_arg(list_arg, int);
	value_string = ft_itoa(value);
	write(1, value_string, ft_strlen(value_string));
	return (1);
}

int		unsigned_int_decimal_arg(const char* string, va_list list_arg)
{
	unsigned int	value;
	char*			value_string;

	(void) string;
	value = va_arg(list_arg, unsigned int);
	value_string = ft_itoa_unsigned(value);
	write(1, value_string, ft_strlen(value_string));
	return (1);
}

int		unsigned_hexadecimal_arg(const char* string, va_list list_arg)
{
	int value;
	char *value_string;

	(void) string;
	value = va_arg(list_arg, unsigned int);
	value_string = ft_itoa_base16(value);
	if (value_string == NULL)
		return(0);
	write(1, value_string, ft_strlen(value_string));
	free(value_string);
	return (1);
}
