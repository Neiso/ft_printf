/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:26:45 by douatla           #+#    #+#             */
/*   Updated: 2020/02/15 19:28:35 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		character_arg(const char* string, va_list list_arg, s_tokken *tokkens)
{
	int bool;
	char value[2];
	char *return_value;

	(void) string;
	value[0] = va_arg(list_arg, int);
	value[1] = '\0';
	bool = 1;
	tokkens->precision = 0;
	if (tokkens->adjustment < 0 && (tokkens->left = 1))
		tokkens->adjustment *= -1;
	if (value[0] == 0)
	{
		tokkens->precision_number = tokkens->precision_number - 1;
		tokkens->adjustment = tokkens->adjustment - 1;
		return_value = read_tokkens_struct(tokkens, value, list_arg, CHARACTER);
		count_character_for_return (tokkens, value);
		if (tokkens->adjustment == 0)
			tokkens->adjustment = 1;
		if (tokkens->left == 1 && !(bool = 0))
			write(1, "\0", 1);
		write(1, return_value, ft_strlen(return_value) + bool);
	}
	else
	{
		return_value = read_tokkens_struct(tokkens, value, list_arg, CHARACTER);
		count_character_for_return (tokkens, return_value);
		write(1, return_value, ft_strlen(return_value));
	}
	return (0);
}
int		string_arg(const char* string, va_list list_arg, s_tokken *tokkens)
{
	char *value;

	(void) string;
	if (tokkens->adjustment < 0 && (tokkens->left = 1))
		tokkens->adjustment = -tokkens->adjustment;
	if (tokkens->precision_number < 0)
		tokkens->precision = 0;
	value = va_arg(list_arg, char*);
	if (value == NULL)
		value = "(null)";
	else if (ft_strlen(value) == 0)
		tokkens->string_tokken.empty_string = 1;
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
	if (tokkens->adjustment < 0 && (tokkens->left = 1))
		tokkens->adjustment = -tokkens->adjustment;
	if (tokkens->precision_number < 0)
		tokkens->precision = 0;
	else if (tokkens->precision_zero_number > 0)
		tokkens->precision_number = tokkens->precision_zero_number;
	value = va_arg(list_arg, int);
	if (value == 0 && tokkens->precision == 1 && tokkens->precision_number == 0)
	{
		tokkens->string_tokken.empty_string = 1;
		value_string = "";
	}
	else
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
	if (tokkens->adjustment < 0 && (tokkens->left = 1))
		tokkens->adjustment = -tokkens->adjustment;
	if (tokkens->precision_number < 0)
		tokkens->precision = 0;
	value = va_arg(list_arg, unsigned int);
	if (value == 0 && tokkens->precision == 1 && tokkens->precision_number == 0)
	{
		tokkens->string_tokken.empty_string = 1;
		value_string = "";
	}
	else
		value_string = ft_itoa_unsigned(value);
	// print_tokken(tokkens);
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
	if (tokkens->adjustment < 0 && (tokkens->left = 1))
		tokkens->adjustment = -tokkens->adjustment;
	if (tokkens->precision_number < 0)
		tokkens->precision = 0;
	value = va_arg(list_arg, unsigned int);
	if (value == 0 && tokkens->precision == 1 && tokkens->precision_number == 0)
	{
		tokkens->string_tokken.empty_string = 1;
		value_string = "";
	}
	else
		value_string = ft_itoa_base16(value);
	if (tokkens->tokken == 'X')
		value_string = toupper_X(value_string);
	if (value_string == NULL)
		return(0);
	// print_tokken(tokkens);
	value_string = read_tokkens_struct(tokkens, value_string, list_arg, INT_D);
	count_character_for_return (tokkens, value_string);
	write(1, value_string, ft_strlen(value_string));
	// free(value_string);
	return (1);
}
