/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 14:23:51 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/20 11:59:38 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	unsigned int c;

	c = 2147483648;
	ft_printf("%u", (unsigned int)c);
	return (0);
}
