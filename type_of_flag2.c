/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_flag2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:45:56 by djulian           #+#    #+#             */
/*   Updated: 2020/02/16 20:03:38 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pointer_arg(const char* string, va_list list_arg, t_tokken *tokkens)
{
	unsigned long int value;
	char *value_string;

	(void) string;
	if (tokkens->adjustment < 0 && (tokkens->left = 1))
		tokkens->adjustment = -tokkens->adjustment;
	if (tokkens->precision_zero_number < 0)
		tokkens->precision = 0;
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

int		pourcent_arg(const char* string, va_list list_arg, t_tokken *tokkens)
{
	(void)string;
	char *value;
	
	if (tokkens->adjustment < 0 && (tokkens->left = 1))
		tokkens->adjustment *= -1;
	if (tokkens->precision_zero == 1)
		tokkens->precision_number = tokkens->adjustment;
	tokkens->precision = 0;
	if (tokkens->precision_zero_number < 0)
		tokkens->precision_zero = 1;
	value = tokkens->tokken == '%' ? "%\0" : "\0";
	// print_tokken(tokkens);
	// printf("VALUE IS : %s\n", value);
	value = read_tokkens_struct(tokkens, value, NULL, POURCENT);
	count_character_for_return (tokkens, value);
	write(1, value, ft_strlen(value));
	return (0);
}