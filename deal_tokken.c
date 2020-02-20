/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_tokken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:01:33 by djulian           #+#    #+#             */
/*   Updated: 2020/02/20 14:28:52 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tokkens_adjustment_left(char *value, char *value_cpy, int adjustment)
{
	int i;
	int len;

	len = (int)ft_strlen(value_cpy);
	ft_strlcpy(value, value_cpy, len + 1);
	i = len - 1;
	while (++i < adjustment)
		value[i] = ' ';
	value[i] = '\0';
}

char	*tokkens_adjustement(int adjustement, char *value, int left)
{
	int		i;
	int		len;
	char	*value_copy;

	len = (int)ft_strlen(value);
	value_copy = ft_strdup(value);
	if (adjustement <= len)
		return (value);
	if (!(value = (char*)malloc(adjustement + 1)))
		return (NULL);
	if (left)
		tokkens_adjustment_left(value, value_copy, adjustement);
	else
	{
		i = -1;
		while (++i < (adjustement - len))
			value[i] = ' ';
		value[i] = '\0';
		ft_strlcat(value, value_copy, adjustement + 1);
	}
	free(value_copy);
	return (value);
}

char	*tokkens_int_precision_neg(char *value, int precision_number, int bool)
{
	int		i;
	int		len;
	char	*value_cpy;

	value_cpy = ft_substr(value, 1, ft_strlen(value));
	if (!(value = (char*)malloc(precision_number + 2)))
		return (NULL);
	value[0] = '-';
	i = 0;
	len = ft_strlen(value_cpy) + bool;
	while (++i < (precision_number - len))
		value[i] = '0';
	value[i] = '\0';
	ft_strlcat(value, value_cpy, precision_number + 1 - bool);
	free(value_cpy);
	return (value);
}

char	*flag_int_preci(char *val, int preci_val, int preci, t_tokken *tokkens)
{
	char	*value_copy;
	int		len;
	int		i;
	int		bool;

	if ((int)ft_strlen(val) > preci_val)
		return (val);
	bool = (preci) ? -1 : 0;
	if (tokkens->precision_zero_number < 0 && val[0] == '-')
		bool += 1;
	if (val[0] == '-')
		val = tokkens_int_precision_neg(val, preci_val, bool);
	else
	{
		value_copy = ft_strdup(val);
		if (!(val = (char*)malloc(preci_val + 1)))
			return (NULL);
		i = -1;
		len = ft_strlen(value_copy);
		while (++i < (preci_val - len))
			val[i] = '0';
		val[i] = '\0';
		ft_strlcat(val, value_copy, preci_val + 1);
	}
	return (val);
}

char	*flag_preci_string(int precision_number, char *value, t_tokken *tokkens)
{
	if (precision_number == 0)
	{
		tokkens->string_tokken.empty_string = 1;
		return ("");
	}
	if (precision_number > (int)ft_strlen(value))
		return (value);
	return (ft_substr((const char*)value, 0, precision_number));
}

char	*tokken_precision_pointer(char *value, int precision_number)
{
	int		i;
	char	*value_cpy;
	int		len;

	i = 0;
	while (value[i] != 'x')
		i++;
	value_cpy = ft_substr(value, ++i, ft_strlen(value));
	value = "0x";
	len = precision_number - ft_strlen(value_cpy);
	i = -1;
	while (++i < len)
		value = ft_strjoin(value, "0");
	value = ft_strjoin(value, value_cpy);
	return (value);
}

char	*read_tokkens_struct(t_tokken *tokkens, char *value, int flag)
{
	if (tokkens->precision == 1 && flag == STRING)
		value = flag_preci_string(tokkens->precision_number, value, tokkens);
	if ((tokkens->precision == 1 || tokkens->precision_zero == 1) && flag == POINTER)
		value = tokken_precision_pointer(value, tokkens->precision_number);
	if (tokkens->precision == 1 && flag != STRING && flag != POINTER)
		value = flag_int_preci(value, tokkens->precision_number, tokkens->precision, tokkens);
	if (tokkens->precision_zero == 1 && tokkens->left == 0 && flag != STRING && flag != POINTER)
		value = flag_int_preci(value, tokkens->precision_number, tokkens->precision, tokkens);
	if (tokkens->adjustment != 0)
		value = tokkens_adjustement(tokkens->adjustment, value, tokkens->left);
	return (value);
}
