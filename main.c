/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:55:19 by djulian           #+#    #+#             */
/*   Updated: 2020/01/29 19:08:19 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int ret = 0;
	int ret2 = 0;
	static char *s_hidden = "hi low\0don't print me lol\0";

	// printf("%d", -1 % 16);

	ret = ft_printf("%5c\n", '\0');
	ret2 =   printf("%5c\n", '\0');
	// printf("ret1 : %d\nret2 : %d\n", ret, ret);
	return (ret);
}