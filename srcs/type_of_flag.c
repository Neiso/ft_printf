/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:26:45 by douatla           #+#    #+#             */
/*   Updated: 2020/02/26 22:12:51 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		character_arg_null(char *value, t_flag *flags)
{
	int		bool;

	bool = 1;
	flags->preci_val = flags->preci_val - 1;
	flags->adjust = flags->adjust - 1;
	if (!(value = read_flags_struct(flags, value, CHARACTER)))
		return (0);
	count_character_for_return(flags, value);
	flags->adjust += 1;
	if (flags->left == 1 && !(bool = 0))
		write(1, "\0", 1);
	write(1, value, ft_strlen(value) + bool);
	free(value);
	return (1);
}

int		character_arg(const char *string, va_list arg, t_flag *flags)
{
	char	*value;

	(void)string;
	if (!(value = (char*)malloc(2)))
		return (0);
	value[0] = va_arg(arg, int);
	if ((int)value[0] == 0 && flags->adjust == 0 && (flags->adjust = 1))
		(flags->string_tokken.empty_string = 1);
	flags->preci = 0;
	if (flags->adjust < 0 && (flags->left = 1))
		flags->adjust *= -1;
	if (!(value[1] = '\0') && value[0] == 0)
		return (character_arg_null(value, flags) ? 1 : 0);
	else
	{
		if (!(value = read_flags_struct(flags, value, CHARACTER)))
			return (0);
		count_character_for_return(flags, value);
		write(1, value, ft_strlen(value));
		free(value);
	}
	return (1);
}

int		string_arg(const char *string, va_list arg, t_flag *flags)
{
	char *value;

	(void)string;
	if (flags->adjust < 0 && (flags->left = 1))
		flags->adjust = -flags->adjust;
	if (flags->preci_val < 0)
		flags->preci = 0;
	value = va_arg(arg, char*);
	if (value == NULL)
		value = ft_strjoin("(null)", "");
	else if (ft_strlen(value) == 0 && (flags->string_tokken.empty_string = 1))
		value = ft_strdup(value);
	else
		value = ft_strdup(value);
	if (value == NULL)
		return (0);
	if (!(value = read_flags_struct(flags, value, STRING)))
		return (0);
	count_character_for_return(flags, value);
	write(1, value, ft_strlen(value));
	free(value);
	return (1);
}

int		int_decimal_arg(const char *string, va_list arg, t_flag *flags)
{
	int		value;
	char	*value_string;

	(void)string;
	if (flags->adjust < 0 && (flags->left = 1))
		flags->adjust = -flags->adjust;
	if (flags->preci_val < 0)
		flags->preci = 0;
	else if (flags->preci_zero_val > 0)
		flags->preci_val = flags->preci_zero_val;
	value = va_arg(arg, int);
	if (value == 0 && flags->preci == 1 && flags->preci_val == 0 &&
			(flags->string_tokken.empty_string = 1))
		value_string = ft_strjoin("", "");
	else
		value_string = ft_itoa(value);
	if (value_string == NULL)
		return (0);
	if (!(value_string = read_flags_struct(flags, value_string, INT_D)))
		return (0);
	count_character_for_return(flags, value_string);
	write(1, value_string, ft_strlen(value_string));
	free(value_string);
	return (1);
}

int		unsigned_int_arg(const char *string, va_list arg, t_flag *flags)
{
	unsigned int	value;
	char			*value_string;

	(void)string;
	if (flags->adjust < 0 && (flags->left = 1))
		flags->adjust = -flags->adjust;
	if (flags->preci_val < 0)
		flags->preci = 0;
	value = va_arg(arg, unsigned int);
	if (value == 0 && flags->preci == 1 && flags->preci_val == 0)
	{
		flags->string_tokken.empty_string = 1;
		value_string = ft_strjoin("", "");
	}
	else
		value_string = ft_itoa_unsigned(value);
	if (value_string == NULL)
		return (0);
	if (!(value_string = read_flags_struct(flags, value_string, INT_D)))
		return (0);
	count_character_for_return(flags, value_string);
	write(1, value_string, ft_strlen(value_string));
	free(value_string);
	return (1);
}
