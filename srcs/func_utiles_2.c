/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utiles_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:06:55 by douatla           #+#    #+#             */
/*   Updated: 2020/02/26 22:01:43 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_adjustment_left(char *value, char *value_cpy, int adjust)
{
	int i;
	int len;

	len = (int)ft_strlen(value_cpy);
	ft_strlcpy(value, value_cpy, len + 1);
	i = len - 1;
	while (++i < adjust)
		value[i] = ' ';
	value[i] = '\0';
}

char	*flags_int_preci_neg(char *value, int bool, t_flag *flags)
{
	int		i;
	int		len;
	char	*value_cpy;

	if (!(value_cpy = ft_substr(value, 1, ft_strlen(value))))
		return (NULL);
	if (flags->preci_val != 0)
		free(value);
	if (!(value = (char*)malloc(flags->preci_val + 2)))
		return (NULL);
	value[0] = '-';
	i = 0;
	len = ft_strlen(value_cpy) + bool;
	while (++i < (flags->preci_val - len))
		value[i] = '0';
	value[i] = '\0';
	ft_strlcat(value, value_cpy, flags->preci_val + 1 - bool);
	free(value_cpy);
	return (value);
}

int		aste2(int i, char *string, va_list arg, t_flag *flags)
{
	int tmp;

	tmp = i;
	if (i - tmp == 0 && string[i] == '*' && string[i + 1] == '.' && ++i)
		asterix(flags, arg, ADJUSTMENT);
	if (i - tmp == 0 && string[i] == '*' && ++i)
		asterix(flags, arg, AD_ZER);
	else if (string[i] == '*' && ++i && (flags->preci_zero = 1))
		asterix(flags, arg, ZERO);
	else if ((flags->preci_zero = 1))
		i = read_value(i - 1, string, ZERO, flags);
	return (i);
}
