/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 10:56:54 by djulian           #+#    #+#             */
/*   Updated: 2019/12/28 10:59:10 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int (*flag_list[8])(const char *string, va_list list_arg, s_tokken *tokkens) =
{
	character_arg,
	string_arg,
	pointer_arg,
	int_decimal_arg,
	int_decimal_arg,
	unsigned_int_decimal_arg,
	unsigned_hexadecimal_arg,
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
		return (HEXA_x);
	else if (str[i] == 'X')
		return (HEXA_X);
	else
		return (-1);
}

int    deal_with_arg(const char *string, va_list list_arg)
{
    char pourcent;
	int flag;
	s_tokken tokkens;

    pourcent = '%';
	flag = type_of_arg(string);
    if (flag != -1)
	{
		init_tokken(&tokkens);
		fill_tokken_struct(&tokkens, string, flag);
		if (tokkens.error != 0)
		{
			write(1, &pourcent, 1);
			return (0);
		}
		flag_list[flag](string, list_arg, &tokkens);
	}
	else if (flag == -1)
    {
        // write(1, &pourcent, 1);
        return (0);
    }
    return (tokkens.adjustment);
}