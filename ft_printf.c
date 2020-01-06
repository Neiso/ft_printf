/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:45:00 by douatla           #+#    #+#             */
/*   Updated: 2019/12/30 12:34:37 by djulian          ###   ########.fr       */
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
	while (string[i] != '\0')
	{
		if (string[i] == '%' && (tmp = deal_with_arg(&string[i], list_arg)))
		{
			i++;
			while (string[i] == '-')
				i++;
			ret += tmp;
			while (string[i] != '\0' && (string[i] <= 97 || string[i] >= 122) && string[i] != 88)
				i++;
			i++;
		}
		else if (string[i] == '%')
		{
			i = find_minus_sign(string, i, &ret);
		}
		ret += 1;
		write(1, &string[i], 1);
		i++;
	}
	va_end(list_arg);
	return (ret);
}