/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:55:19 by djulian           #+#    #+#             */
/*   Updated: 2019/12/28 11:44:11 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int ret = 0;
	int ret2 = 0;

	ret = ft_printf("ft_printf output : %c\n", 0);
	ret2 = printf("   printf output : %c\n", 0);
	// ft_printf("ret ft_printf : %d\nret printf : %d\n", ret, ret2);
	return (ret);
}