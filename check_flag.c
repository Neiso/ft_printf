/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 10:56:54 by djulian           #+#    #+#             */
/*   Updated: 2019/12/24 11:47:41 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int (*flag_list[8])(const char *string, va_list list_arg) =
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
		return (0);
	else if (str[i] == 's')
		return (1);
	else if (str[i] == 'p')
		return (2);
	else if (str[i] == 'd')
		return (3);
	else if (str[i] == 'i')
		return (4);
	else if (str[i] == 'u')
		return (5);
	else if (str[i] == 'x')
		return (6);
	else if (str[i] == 'X')
		return (7);
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
		// print_tokken(&tokkens);
		if (tokkens.error != 0)
			return (0);
		flag_list[flag](string, list_arg);
	}
	else if (flag == -1)
    {
        write(1, &pourcent, 1);
        return (0);
    }
    return (1);
}