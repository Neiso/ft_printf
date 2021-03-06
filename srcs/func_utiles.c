/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 13:26:48 by djulian           #+#    #+#             */
/*   Updated: 2020/02/25 20:53:59 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_unsigned(unsigned long int n)
{
	int					i;
	char				*str;
	unsigned long int	tmp;

	tmp = n;
	i = 1;
	while ((tmp = tmp / 10))
		i++;
	if (n != 0 && (!(str = (char*)malloc(i + 2))))
		return (NULL);
	if (n == 0 && (!(str = (char*)malloc(i + 1))))
		return (NULL);
	str[i] = '\0';
	str[0] = '\0';
	tmp = (long)n;
	i--;
	str[i] = n == 0 ? '0' : '\0';
	while (tmp)
	{
		str[i] = (char)((tmp % 10) + 48);
		tmp = tmp / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa_base16(unsigned int n)
{
	int				i;
	unsigned int	tmp;
	char			*base;
	char			*string;

	if (n == 0)
		return (ft_strjoin("0", ""));
	base = "0123456789abcdef";
	tmp = n;
	i = 1;
	while ((tmp = tmp / 16))
		i++;
	if (!(string = (char*)malloc(i + 1)))
		return (NULL);
	string[i] = '\0';
	while (n)
	{
		string[i - 1] = base[n % 16];
		n = n / 16;
		i--;
	}
	return (string);
}

char	*ft_itoa_base16_long(unsigned long int n)
{
	int					i;
	unsigned long int	tmp;
	char				*base;
	char				*string;

	if (n == 0)
		return (ft_strjoin("0", ""));
	base = "0123456789abcdef";
	tmp = n;
	i = 1;
	while ((tmp = tmp / 16))
		i++;
	if (!(string = (char*)malloc(i + 1)))
		return (NULL);
	string[i] = '\0';
	while (n)
	{
		string[i - 1] = base[n % 16];
		n = n / 16;
		i--;
	}
	return (string);
}

void	count_character_for_return(t_flag *flags, char *value)
{
	if (flags->tokken == 'c' && flags->adjust != 0)
		return ;
	else
		flags->adjust = ft_strlen(value);
}

char	*toupper_x(char *value_string)
{
	int i;

	i = -1;
	while (value_string[++i])
	{
		if (value_string[i] >= 97 && value_string[i] <= 122)
			value_string[i] -= 32;
	}
	return (value_string);
}
