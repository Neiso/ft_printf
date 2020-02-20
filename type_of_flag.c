/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:26:45 by douatla           #+#    #+#             */
/*   Updated: 2020/02/19 23:26:41 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		character_arg_null(char value[2], t_tokken *tokkens)
{
	char	*return_value;
	int		bool;

	bool = 1;
	tokkens->precision_number = tokkens->precision_number - 1;
	tokkens->adjustment = tokkens->adjustment - 1;
	return_value = read_tokkens_struct(tokkens, value, CHARACTER);
	count_character_for_return(tokkens, value);\
	tokkens->adjustment += 1;
	if (tokkens->left == 1 && !(bool = 0))
		write(1, "\0", 1);
	write(1, return_value, ft_strlen(return_value) + bool);
	return (0);
}

int		character_arg(const char *string, va_list arg, t_tokken *tokkens)
{
	char	value[2];
	char	*return_value;

	(void)string;
	value[0] = va_arg(arg, int);
	tokkens->precision = 0;
	if (tokkens->adjustment < 0 && (tokkens->left = 1))
		tokkens->adjustment *= -1;
	if (!(value[1] = '\0') && value[0] == 0)
		character_arg_null(value, tokkens);
	else
	{
		return_value = read_tokkens_struct(tokkens, value, CHARACTER);
		count_character_for_return(tokkens, return_value);
		write(1, return_value, ft_strlen(return_value));
	}
	return (1);
}

int		string_arg(const char *string, va_list arg, t_tokken *tokkens)
{
	char *value;

	(void)string;
	if (tokkens->adjustment < 0 && (tokkens->left = 1))
		tokkens->adjustment = -tokkens->adjustment;
	if (tokkens->precision_number < 0)
		tokkens->precision = 0;
	value = va_arg(arg, char*);
	if (value == NULL)
		value = "(null)";
	else if (ft_strlen(value) == 0)
		tokkens->string_tokken.empty_string = 1;
	value = read_tokkens_struct(tokkens, value, STRING);
	count_character_for_return(tokkens, value);
	write(1, value, ft_strlen(value));
	return (1);
}

int		int_decimal_arg(const char *string, va_list arg, t_tokken *tokkens)
{
	int		value;
	char	*value_string;

	(void)string;
	if (tokkens->adjustment < 0 && (tokkens->left = 1))
		tokkens->adjustment = -tokkens->adjustment;
	if (tokkens->precision_number < 0)
		tokkens->precision = 0;
	else if (tokkens->precision_zero_number > 0)
		tokkens->precision_number = tokkens->precision_zero_number;
	value = va_arg(arg, int);
	if (value == 0 && tokkens->precision == 1 && tokkens->precision_number == 0)
	{
		tokkens->string_tokken.empty_string = 1;
		value_string = "";
	}
	else
		value_string = ft_itoa(value);
	value_string = read_tokkens_struct(tokkens, value_string, INT_D);
	count_character_for_return(tokkens, value_string);
	write(1, value_string, ft_strlen(value_string));
	return (1);
}

int		unsigned_int_arg(const char *string, va_list arg, t_tokken *tokkens)
{
	unsigned int	value;
	char			*value_string;

	(void)string;
	if (tokkens->adjustment < 0 && (tokkens->left = 1))
		tokkens->adjustment = -tokkens->adjustment;
	if (tokkens->precision_number < 0)
		tokkens->precision = 0;
	value = va_arg(arg, unsigned int);
	if (value == 0 && tokkens->precision == 1 && tokkens->precision_number == 0)
	{
		tokkens->string_tokken.empty_string = 1;
		value_string = "";
	}
	else
		value_string = ft_itoa_unsigned(value);
	value_string = read_tokkens_struct(tokkens, value_string, INT_D);
	count_character_for_return(tokkens, value_string);
	write(1, value_string, ft_strlen(value_string));
	return (1);
}
