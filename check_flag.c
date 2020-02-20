/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 10:56:54 by djulian           #+#    #+#             */
/*   Updated: 2020/02/20 14:33:31 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int (*g_tokken_list[9])(const char *string, va_list arg, t_tokken *tokkens) =
{
	character_arg,
	string_arg,
	pointer_arg,
	int_decimal_arg,
	int_decimal_arg,
	unsigned_int_arg,
	unsigned_hexa_arg,
	unsigned_hexa_arg,
	pourcent_arg
};

int		type_of_arg(const char *str)
{
	int i;

	i = 1;
	while (str[i] != '\0' && (str[i] <= 97 || str[i] >= 122) &&
			str[i] != 88 && str[i] != '%')
		i++;
	if (str[i] == 'c')
		return (CHARACTER);
	else if (str[i] == 's')
		return (STRING);
	else if (str[i] == 'p')
		return (POINTER);
	else if (str[i] == 'd')
		return (INT_D);
	else if (str[i] == 'i')
		return (INT_I);
	else if (str[i] == 'u')
		return (UNSI_INT);
	else if (str[i] == 'x')
		return (HEXA_XS);
	else if (str[i] == 'X')
		return (HEXA_X);
	else if (str[i] == '%')
		return (POURCENT);
	return (-1);
}

int		deal_with_arg(const char *string, va_list list_arg)
{
	int			flag;
	int			ret;
	t_tokken	tokkens;

	ret = 0;
	flag = type_of_arg(string);
	if (flag != -1)
	{
		init_tokken(&tokkens);
		tokkens.tokken = FLAG[flag];
		fill_struct(&tokkens, (char *)string, flag, list_arg);
		if (tokkens.precision_zero_number < 0)
			tokkens.precision_number = tokkens.adjustment;
		g_tokken_list[flag](string, list_arg, &tokkens);
	}
	else if (flag == -1)
		return (0);
	if (tokkens.string_tokken.empty_string && tokkens.adjustment == 0)
		return (EMPTY_STRING);
	return (tokkens.adjustment);
}
