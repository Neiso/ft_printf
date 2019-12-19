/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:45:00 by douatla           #+#    #+#             */
/*   Updated: 2019/12/19 17:51:43 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int (*flag_list[7])(const char *string, va_list list_arg) =
{
	character_arg,
	string_arg,
	pointer_arg,
	int_decimal_arg,
	unsigned_int_decimal_arg,
	unsigned_hexadecimal_arg
};

int		type_of_arg(const char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return(-1);
	while (str[i] != '\0' && (str[i] <= 97 || str[i] >= 122) && str[i] != 88)
		i++;
	if (str[i] == 'c')
		return (0);
	else if (str[i] == 's')
		return (1);
	else if (str[i] == 'p')
		return (2);
	else if (str[i] == 'd' || str[i] == 'i')
		return (3);
	else if (str[i] == 'u')
		return (4);
	else if (str[i] == 'x' || str[i] == 'X')
		return (5);
	else
		return (-1);
}

const char	*find_next_arg(const char *string)
{
	static int i = 0;
	while (string[i] != '%' && string[i] != '\0')
		i++;
	if (string[i] == '\0')
		return (NULL);
	i++;
	return (&string[i]);
}

int		deal_with_arg(const char *string, va_list list_arg)
{
	const char *argument;
	int flag;
	int ret;

	argument = find_next_arg(string);
	flag = type_of_arg(argument);
	if (flag != -1)
		flag_list[flag](string, list_arg);
	return (1);
}

int		ft_printf(const char *string, ...)
{
	va_list list_arg;
	int		i;
	char	**split;
	char	*buffer;

	va_start(list_arg, string);
	i = 0;
	buffer = "\0";
	split = NULL;
	split = ft_split(string, '%');
	while (split[i] != NULL)
	{
		write(1, split[i], ft_strlen(split[i]));
		buffer = ft_strjoin(buffer, split[i]);
		i++;
		deal_with_arg(string, list_arg);
	}
	va_end(list_arg);
	// write(1, buffer, ft_strlen(buffer));
	return (1);
}