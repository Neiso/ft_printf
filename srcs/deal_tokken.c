/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_tokken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:01:33 by djulian           #+#    #+#             */
/*   Updated: 2020/03/03 09:09:20 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flags_adjustement(int adjust, char *value, int left)
{
	int		i;
	int		len;
	char	*value_copy;

	len = (int)ft_strlen(value);
	if (adjust <= len)
		return (value);
	if (!(value_copy = ft_strdup(value)))
		return (NULL);
	free(value);
	if (!(value = (char*)malloc(adjust + 1)))
		return (NULL);
	if (left)
		flags_adjustment_left(value, value_copy, adjust);
	else
	{
		i = -1;
		while (++i < (adjust - len))
			value[i] = ' ';
		value[i] = '\0';
		ft_strlcat(value, value_copy, adjust + 1);
	}
	free(value_copy);
	return (value);
}

char	*flag_int_preci(char *val, int preci_val, int preci, t_flag *flags)
{
	char	*value_copy;
	int		i;
	int		bool;

	if ((int)ft_strlen(val) > preci_val)
		return (val);
	bool = (preci) ? -1 : 0;
	if (flags->preci_zero_val < 0 && val[0] == '-')
		bool += 1;
	if (val[0] == '-')
		val = flags_int_preci_neg(val, bool, flags);
	else
	{
		free(val);
		if (!(value_copy = ft_strdup(val)) ||
			!(val = (char*)malloc(preci_val + 1)))
			return (NULL);
		i = -1;
		while (++i < (preci_val - ((int)ft_strlen(value_copy))))
			val[i] = '0';
		val[i] = '\0';
		ft_strlcat(val, value_copy, preci_val + 1);
		free(value_copy);
	}
	return (val);
}

char	*flag_preci_string(int preci_val, char *value, t_flag *flags)
{
	if (preci_val == 0)
	{
		flags->string_tokken.empty_string = 1;
		free(value);
		return (ft_strjoin("", ""));
	}
	if (preci_val > (int)ft_strlen(value))
		return (value);
	value = ft_substr((const char*)value, 0, preci_val);
	return (value);
}

char	*tokken_preci_pointer(char *value, int preci_val)
{
	int		i;
	char	*value_cpy;
	char	*value2;
	int		len;

	i = 1;
	if (!(value_cpy = ft_substr(value, ++i, ft_strlen(value))))
		return (NULL);
	len = preci_val - ft_strlen(value_cpy);
	i = 0;
	while (i < len)
		i++;
	if (!(value2 = (char*)malloc(i + 3)))
		return (NULL);
	ft_strlcat(value2, "0x", 3);
	i = -1;
	while (++i < len)
		value2[i + 2] = '0';
	value2[i + 2] = '\0';
	free(value);
	value = ft_strjoin(value2, value_cpy);
	free(value_cpy);
	free(value2);
	return (value);
}

char	*read_flags_struct(t_flag *flags, char *value, int flag)
{
	if (flags->preci == 1 && flag == STRING)
		value = flag_preci_string(flags->preci_val, value, flags);
	if ((flags->preci == 1 || flags->preci_zero == 1) && flag == POINTER)
		value = tokken_preci_pointer(value, flags->preci_val);
	if (flags->preci == 1 && flag != STRING && flag != POINTER)
		value = flag_int_preci(value, flags->preci_val, flags->preci, flags);
	if (value == NULL)
		return (0);
	if (flags->preci_zero == 1 && flags->left == 0
			&& flag != STRING && flag != POINTER)
		value = flag_int_preci(value, flags->preci_val, flags->preci, flags);
	if (value == NULL)
		return (0);
	if (flags->adjust != 0)
		value = flags_adjustement(flags->adjust, value, flags->left);
	if (value == NULL)
		return (0);
	return (value);
}
