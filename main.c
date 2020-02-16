/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:55:19 by djulian           #+#    #+#             */
/*   Updated: 2020/02/16 18:42:59 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int ret = 0;
	int ret2 = 0;
	static char *s_hidden = "hi low\0don't print me lol\0";

	ret = ft_printf("<%-20p>\n" ,s_hidden);
	ret2 =   printf("<%-20p>\n" ,s_hidden);
	// ret2 =   printf("%", '\0');
	printf("\nret1 : %d\nret2 : %d\n", ret, ret2);
	return (ret);
}

	// ret2 =   printf("%00*x\n" ,-186,3071966434u);
	// ret = ft_printf("%00*x\n" ,-186,3071966434u);
	// ret2 =   printf("%00*.22d\n" ,-174,1782663194);
	// ret = ft_printf("%00*.22d\n" ,-174,1782663194);