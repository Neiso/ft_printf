/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 10:56:54 by djulian           #+#    #+#             */
/*   Updated: 2019/12/23 16:54:10 by djulian          ###   ########.fr       */
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

int    deal_with_arg(const char *string, va_list list_arg)
{
    char pourcent;
	int flag;

    pourcent = '%';
	flag = type_of_arg(string);
    if (flag != -1)
		flag_list[flag](string, list_arg);
	else if (flag == -1)
    {
        write(1, &pourcent, 1);
        return (0);
    }
    return (1);
}