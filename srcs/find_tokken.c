/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tokken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:05:24 by djulian           #+#    #+#             */
/*   Updated: 2020/02/26 22:03:00 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		*init_tokken(t_flag *flags)
{
	flags->adjust = 0;
	flags->left = 0;
	flags->preci = 0;
	flags->preci_val = 0;
	flags->preci_zero = 0;
	flags->preci_zero_val = 0;
	flags->tokken = 0;
	flags->string_tokken.empty_string = 0;
	flags->string_tokken.precision_zero_string = 0;
	return (flags);
}

int			asterix(t_flag *flags, va_list arg, int flag)
{
	if (flag == PRECISION && flags->preci_zero == 1)
	{
		flags->preci_zero_val = va_arg(arg, int);
		if (flags->preci_zero_val < 0)
			flags->preci_zero = 0;
		else
			flags->preci_val = flags->preci_zero_val;
	}
	else if (flag == AD_ZER && flags->tokken == '%' && (flags->preci_zero = 1))
		flags->adjust = va_arg(arg, int);
	else if (flag == AD_ZER)
	{
		flags->preci_zero_val = va_arg(arg, int);
		if (flags->preci_zero_val > 0 && (flags->preci_zero = 1))
			flags->preci_val = flags->preci_zero_val;
		else if ((flags->left = 1))
			flags->adjust = -flags->preci_zero_val;
	}
	else if (flag == ADJUSTMENT)
		flags->adjust = va_arg(arg, int);
	else if (flag == PRECISION || flag == ZERO)
		flags->preci_val = va_arg(arg, int);
	else if (flag == ZERO && flags->tokken == '%')
		flags->adjust = va_arg(arg, int);
	return (1);
}

int			read_value(int pos, const char *str, int tokken, t_flag *flags)
{
	int		tmp;
	int		value;
	char	*value_string;

	value = 0;
	tmp = ++pos;
	while (str[pos] >= '0' && str[pos] <= '9')
		pos++;
	value_string = ft_substr(str, tmp, pos);
	value = ft_atoi(value_string);
	free(value_string);
	if (tokken == MINUS_SIGN && (flags->left = 1))
		flags->adjust = value;
	else if (tokken == PRECISION && (flags->preci = 1))
		flags->preci_val = value;
	else if (tokken == ZERO)
		flags->preci_val = value;
	else if (pos != 1 && flags->adjust == 0)
		flags->adjust = value;
	return (pos);
}

int			pre_fill(t_flag *flags, const char *string, va_list arg)
{
	int		i;
	int		tmp;
	char	*val;

	i = 1;
	while (string[i] == '-' && ++i)
		flags->left = 1;
	tmp = i;
	if (string[i] == '0' && flags->left == 0)
	{
		while ((tmp = i) && string[i] == '0')
			i++;
		i = aste2(i, (char*)string, arg, flags);
	}
	while (string[i] >= '0' && string[i] <= '9')
		i++;
	if (i != 1 && flags->adjust == 0)
	{
		val = ft_substr(string, tmp, i);
		flags->adjust = ft_atoi(val);
		free(val);
	}
	return (i);
}

t_flag		*fill_struct(t_flag *flags, char *str, int flag, va_list arg)
{
	int		i;

	i = pre_fill(flags, str, arg);
	while (str[i] != FLAG[flag])
	{
		if (str[i] == '-')
		{
			if (str[i + 1] == '*' && ++i && ++i)
				asterix(flags, arg, ADJUSTMENT);
			else
				i = read_value(i, str, MINUS_SIGN, flags);
		}
		else if (str[i] == '.')
		{
			if (str[i + 1] == '*' && ++i && ++i && (flags->preci = 1))
				asterix(flags, arg, PRECISION);
			else
				i = read_value(i, str, PRECISION, flags);
		}
		else if (str[i] == '*' && ++i)
			asterix(flags, arg, ADJUSTMENT);
		else
			i++;
	}
	return (flags);
}
