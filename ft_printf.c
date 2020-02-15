/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:45:00 by douatla           #+#    #+#             */
/*   Updated: 2020/02/13 18:11:26 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *string, ...)
{
	va_list list_arg;
	int		i;
	int ret;
	int tmp;

	va_start(list_arg, string);
	i = 0;
	ret = 0;
	tmp = 0;
	while (string[i] != '\0')
	{
		while (string[i] == '%' && (tmp = deal_with_arg(&string[i], list_arg)))
		{
			if (tmp != EMPTY_STRING)
				ret += tmp;
			i++;
			while (string[i] != '\0' && (string[i] <= 97 || string[i] >= 122) && string[i] != 88 && string[i] != '%')
				i++;
			i++;
		}
		if (string[i] == '%' && ++i)
		{
			while((string[i] >= '0' && string[i] <= '9') || string[i] == '-' || string[i] == '*' || string[i] == '.')
				i++;
		}
		if (string[i] != '\0')
		{
			ret += 1;
			write(1, &string[i], 1);
			i++;
		}
	}
	va_end(list_arg);
	return (ret);
}
