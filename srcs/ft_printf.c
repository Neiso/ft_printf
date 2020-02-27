/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:45:00 by douatla           #+#    #+#             */
/*   Updated: 2020/02/26 21:53:19 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_tokken(const char *string, int *ret, int pos, int tmp)
{
	if (tmp == -2)
		return (0);
	if (++pos && tmp != EMPTY_STRING)
		*ret += tmp;
	while (string[pos] != '\0' && (string[pos] <= 97 ||
			string[pos] >= 122) && string[pos] != 88 && string[pos] != '%')
		pos++;
	return (pos + 1);
}

int		ft_printf(const char *string, ...)
{
	va_list			list_arg;
	int				i;
	static int		ret = 0;
	int				tmp;

	va_start(list_arg, string);
	i = 0;
	while (string[i] != '\0')
	{
		while (string[i] == '%' && (tmp = deal_with_arg(&string[i], list_arg)))
		{
			if (!(i = ft_printf_tokken(string, &ret, i, tmp)))
				return (-1);
		}
		if (string[i] == '%' && ++i)
		{
			while ((string[i] >= '0' && string[i] <= '9') ||
					string[i] == '-' || string[i] == '*' || string[i] == '.')
				i++;
		}
		if (string[i] != '\0' && (ret += 1))
			write(1, &string[i++], 1);
	}
	va_end(list_arg);
	return (ret);
}
