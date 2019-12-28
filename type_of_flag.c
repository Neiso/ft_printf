/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:26:45 by douatla           #+#    #+#             */
/*   Updated: 2019/12/28 12:13:55 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		character_arg(const char* string, va_list list_arg, s_tokken *tokkens)
{
	char value[2];
	char arg;
	char *return_value;

	(void) string;
	arg = va_arg(list_arg, int);
	if (arg == 0)
		value[0] = 0x40;
	else
		value[0] = arg;
	value[1] = '\0';
	return_value = read_tokkens_struct(tokkens, value, list_arg, CHARACTER);
	count_character_for_return (tokkens, value);	
	write(1, return_value, ft_strlen(return_value));
	return (0);
}
int		string_arg(const char* string, va_list list_arg, s_tokken *tokkens)
{
	char *value;

	(void) string;
	value = va_arg(list_arg, char*);
	value = read_tokkens_struct(tokkens, value, list_arg, STRING);
	count_character_for_return (tokkens, value);
	write(1, value, ft_strlen(value));
	return (1);
}
int		int_decimal_arg(const char *string, va_list list_arg, s_tokken *tokkens)
{
	int value;
	char *value_string;

	(void) string;
	value = va_arg(list_arg, int);
	value_string = ft_itoa(value);
	value_string = read_tokkens_struct(tokkens, value_string, list_arg, INT_D);
	count_character_for_return (tokkens, value_string);
	write(1, value_string, ft_strlen(value_string));
	return (1);
}

int		unsigned_int_decimal_arg(const char* string, va_list list_arg, s_tokken *tokkens)
{
	unsigned int	value;
	char*			value_string;

	(void) string;
	value = va_arg(list_arg, unsigned int);
	value_string = ft_itoa_unsigned(value);
	value_string = read_tokkens_struct(tokkens, value_string, list_arg, INT_D);
	count_character_for_return (tokkens, value_string);
	write(1, value_string, ft_strlen(value_string));
	return (1);
}

int		unsigned_hexadecimal_arg(const char* string, va_list list_arg, s_tokken *tokkens)
{
	int value;
	char *value_string;

	(void) string;
	value = va_arg(list_arg, unsigned int);
	value_string = ft_itoa_base16(value);
	if (value_string == NULL)
		return(0);
	value_string = read_tokkens_struct(tokkens, value_string, list_arg, INT_D);
	count_character_for_return (tokkens, value_string);
	write(1, value_string, ft_strlen(value_string));
	free(value_string);
	return (1);
}
