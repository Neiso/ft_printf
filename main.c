/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:55:19 by djulian           #+#    #+#             */
/*   Updated: 2019/12/24 12:17:59 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	ft_printf ("jespere c pas cassez : %---12.213w\n", "Hello world");
	printf ("jespere c pas cassez : <%.0s>\n", "Hello");
	return (1);
}