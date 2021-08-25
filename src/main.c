/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 14:23:51 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/25 15:07:50 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

// make re DEBUG=1 main; ./printf_gdb

int	main(void)
{
	char	c;

	c = '%';
	ft_printf("%%", c);
	return (0);
}
