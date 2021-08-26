/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printpnt.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:26:09 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/26 18:26:33 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printpnt(size_t *len, unsigned long ul)
{
	char	*result;

	ft_putstr_fd("0x", 1);
	result = ft_ultoh(ul);
	ft_putstr_fd(result, 1);
	*len += ft_strlen(result) + 2;
	free(result);
	return ;
}
