/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printchr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:29:48 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/26 18:30:25 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printchr(size_t *len, int c)
{
	ft_putchar_fd(c, 1);
	*len += 1;
	return ;
}
