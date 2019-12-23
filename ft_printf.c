/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:45:00 by douatla           #+#    #+#             */
/*   Updated: 2019/12/23 13:10:12 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *string, ...)
{
	va_list list_arg;
	int		i;
	char	*buffer;

	va_start(list_arg, string);
	i = 0;
	buffer = "\0";
	while (string[i] != '\0')
	{
		if (string[i] == '%' && deal_with_arg(&string[i], list_arg))
			i++;
		else if (string[i] == '%' && string[++i] != '\0')
			write(1, &string[i], 1);
		else 
			write(1, &string[i], 1);
		i++;
	}
	write(1, buffer, ft_strlen(buffer));
	va_end(list_arg);
	return (1);
}