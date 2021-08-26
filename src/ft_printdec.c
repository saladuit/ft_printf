/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printdec.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:28:42 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/26 18:29:08 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printdec(size_t *len, int n)
{
	ft_putnbr_fd(n, 1);
	*len += ft_numlen(n);
	return ;
}
