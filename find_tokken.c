/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tokken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:05:24 by djulian           #+#    #+#             */
/*   Updated: 2020/02/19 23:16:07 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tokken	*init_tokken(t_tokken *tokkens)
{
	tokkens->adjustment = 0;
	tokkens->left = 0;
	tokkens->precision = 0;
	tokkens->precision_number = 0;
	tokkens->precision_zero = 0;
	tokkens->precision_zero_number = 0;
	tokkens->tokken = 0;
	tokkens->string_tokken.empty_string = 0;
	tokkens->string_tokken.precision_zero_string = 0;
	return (tokkens);
}

int			asterix(t_tokken *tokkens, va_list arg, int flag)
{
	if (flag == PRECISION && tokkens->precision_zero == 1)
	{
		tokkens->precision_zero_number = va_arg(arg, int);
		if (tokkens->precision_zero_number < 0)
			tokkens->precision_zero = 0;
		else
			tokkens->precision_number = tokkens->precision_zero_number;
	}
	else if (flag == ADJUST_ZERO && tokkens->tokken == '%')
		tokkens->adjustment = va_arg(arg, int);
	else if (flag == ADJUST_ZERO)
	{
		tokkens->precision_zero_number = va_arg(arg, int);
		if (tokkens->precision_zero_number > 0 && (tokkens->precision_zero = 1))
			tokkens->precision_number = tokkens->precision_zero_number;
		else if ((tokkens->left = 1))
			tokkens->adjustment = -tokkens->precision_zero_number;
	}
	else if (flag == ADJUSTMENT)
		tokkens->adjustment = va_arg(arg, int);
	else if (flag == PRECISION || flag == ZERO)
		tokkens->precision_number = va_arg(arg, int);
	else if (flag == ZERO && tokkens->tokken == '%')
		tokkens->adjustment = va_arg(arg, int);
	return (1);
}

int			read_value(int pos, const char *str, int tokken, t_tokken *tokkens)
{
	int tmp;
	int value;

	value = 0;
	tmp = ++pos;
	while (str[pos] >= '0' && str[pos] <= '9')
		pos++;
	value = ft_atoi(ft_substr(str, tmp, pos));
	if (tokken == MINUS_SIGN && (tokkens->left = 1))
		tokkens->adjustment = value;
	else if (tokken == PRECISION && (tokkens->precision = 1))
		tokkens->precision_number = value;
	else if (tokken == ZERO)
		tokkens->precision_number = value;
	else if (pos != 1 && tokkens->adjustment == 0)
		tokkens->adjustment = value;
	return (pos);
}

int			pre_fill(t_tokken *tokkens, const char *string, va_list arg)
{
	int i;
	int tmp;

	i = 1;
	while (string[i] == '-' && ++i)
		tokkens->left = 1;
	tmp = i;
	if (string[i] == '0' && tokkens->left == 0)
	{
		while ((tmp = i) && string[i] == '0')
			i++;
		if (i - tmp == 0 && string[i] == '*' && string[i + 1] == '.' && ++i)
			asterix(tokkens, arg, ADJUSTMENT);
		if (i - tmp == 0 && string[i] == '*' && ++i)
			asterix(tokkens, arg, ADJUST_ZERO);
		else if (string[i] == '*' && ++i && (tokkens->precision_zero = 1))
			asterix(tokkens, arg, ZERO);
		else if ((tokkens->precision_zero = 1))
			i = read_value(i - 1, string, ZERO, tokkens);
	}
	while (string[i] >= '0' && string[i] <= '9')
		i++;
	if (i != 1 && tokkens->adjustment == 0)
		tokkens->adjustment = ft_atoi(ft_substr(string, tmp, i));
	return (i);
}

t_tokken	*fill_struct(t_tokken *tokkens, char *str, int flags, va_list arg)
{
	int		i;

	i = pre_fill(tokkens, str, arg);
	while (str[i] != FLAG[flags])
	{
		if (str[i] == '-')
		{
			if (str[i + 1] == '*' && ++i && ++i)
				asterix(tokkens, arg, ADJUSTMENT);
			else
				i = read_value(i, str, MINUS_SIGN, tokkens);
		}
		else if (str[i] == '.')
		{
			if (str[i + 1] == '*' && ++i && ++i && (tokkens->precision = 1))
				asterix(tokkens, arg, PRECISION);
			else
				i = read_value(i, str, PRECISION, tokkens);
		}
		else if (str[i] == '*' && ++i)
			asterix(tokkens, arg, ADJUSTMENT);
		else
			i++;
	}
	return (tokkens);
}
