/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_flag2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:45:56 by djulian           #+#    #+#             */
/*   Updated: 2020/02/09 10:48:43 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pointer_arg(const char* string, va_list list_arg, s_tokken *tokkens)
{
	unsigned long int value;
	char *value_string;

	(void) string;
	if (tokkens->asterix == 1)
		tokkens->adjustment = va_arg(list_arg, int);
	value = va_arg(list_arg, unsigned long int);
	value_string = ft_itoa_base16_long(value);
	if (value_string == NULL)
		return(0);
	if (value == 0 && tokkens->precision == 0)
		value_string = "0x0";
	else if (value == 0 && tokkens->precision == 1 && tokkens->precision == 1)
		value_string = "0x";
	else
		value_string = ft_strjoin("0x", value_string);
	value_string = read_tokkens_struct(tokkens, value_string, list_arg, POINTER);
	count_character_for_return (tokkens, value_string);
	write(1, value_string, ft_strlen(value_string));
	return (0);
}

int		pourcent_arg(const char* string, va_list list_arg, s_tokken *tokkens)
{
	(void)string;
	char *value;

	if (tokkens->asterix == 1)
		tokkens->adjustment = va_arg(list_arg, int);
	value = tokkens->tokken == '%' ? "%\0" : "\0";
	value = read_tokkens_struct(tokkens, value, NULL, POURCENT);
	count_character_for_return (tokkens, value);
	write(1, value, ft_strlen(value));
	return (0);
}