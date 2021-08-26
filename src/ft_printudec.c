/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printudec.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:27:52 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/26 18:28:31 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printudec(size_t *len, unsigned int n)
{
	ft_putuint_fd(n, 1);
	*len += ft_numlen(n);
	return ;
}
