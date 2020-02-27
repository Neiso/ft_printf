/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_flag2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:45:56 by djulian           #+#    #+#             */
/*   Updated: 2020/02/26 22:13:00 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unsigned_hexa_arg(const char *string, va_list arg, t_flag *flags)
{
	int		value;
	char	*value_string;

	(void)string;
	if (flags->adjust < 0 && (flags->left = 1))
		flags->adjust = -flags->adjust;
	if (flags->preci_val < 0)
		flags->preci = 0;
	value = va_arg(arg, unsigned int);
	if (value == 0 && flags->preci == 1 && flags->preci_val == 0 &&
			(flags->string_tokken.empty_string = 1))
		value_string = ft_strjoin("", "");
	else
		value_string = ft_itoa_base16(value);
	if (value_string == NULL)
		return (0);
	if (flags->tokken == 'X')
		value_string = toupper_x(value_string);
	if (!(value_string = read_flags_struct(flags, value_string, INT_D)))
		return (0);
	count_character_for_return(flags, value_string);
	write(1, value_string, ft_strlen(value_string));
	free(value_string);
	return (1);
}

char	*pointer_arg_2(unsigned long int value, t_flag *flags)
{
	char	*value_string;
	char	*value_string_cpy;

	if (value == 0 && flags->preci == 0)
		value_string = ft_strjoin("0x0", "");
	else if (value == 0 && flags->preci == 1)
		value_string = ft_strjoin("0x", "");
	else
		value_string = ft_itoa_base16_long(value);
	if (value_string == NULL)
		return (0);
	else if (value != 0)
	{
		value_string_cpy = ft_strdup(value_string);
		free(value_string);
		if (value_string_cpy == NULL)
			return (NULL);
		value_string = ft_strjoin("0x", value_string_cpy);
		free(value_string_cpy);
		if (value_string == NULL)
			return (NULL);
	}
	return (value_string);
}

int		pointer_arg(const char *string, va_list arg, t_flag *flags)
{
	unsigned long int	value;
	char				*value_string;

	(void)string;
	if (flags->adjust < 0 && (flags->left = 1))
		flags->adjust = -flags->adjust;
	if (flags->preci_zero_val < 0)
		flags->preci = 0;
	value = va_arg(arg, unsigned long int);
	if (!(value_string = pointer_arg_2(value, flags)))
		return (0);
	value_string = read_flags_struct(flags, value_string, POINTER);
	count_character_for_return(flags, value_string);
	write(1, value_string, ft_strlen(value_string));
	free(value_string);
	return (1);
}

int		pourcent_arg(const char *string, va_list arg, t_flag *flags)
{
	char *value;

	(void)string;
	arg = 0;
	if (flags->adjust < 0 && (flags->left = 1))
		flags->adjust *= -1;
	if (flags->preci_zero == 1)
		flags->preci_val = flags->adjust;
	flags->preci = 0;
	if (flags->preci_zero_val < 0)
		flags->preci_zero = 1;
	if (!(value = ft_strjoin("%", "")))
		return (0);
	if (!(value = read_flags_struct(flags, value, POURCENT)))
		return (0);
	count_character_for_return(flags, value);
	write(1, value, ft_strlen(value));
	free(value);
	return (1);
}
