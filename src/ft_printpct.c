/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printpct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:23:54 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/26 18:25:22 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printpct(size_t *len)
{
	ft_putchar_fd('%', 1);
	*len += 1;
	return ;
}
