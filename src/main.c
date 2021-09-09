/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 14:23:51 by safoh         #+#    #+#                 */
/*   Updated: 2021/09/09 15:26:00 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

// make re DEBUG=1 main; ./printf_gdb

int	main(void)
{
	unsigned int	c;

	c = 0;
	ft_printf("%X", c);
	return (0);
}
